#include <iostream> 
#include <stdexcept>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include <string>
#include <cstring>
#include <iterator>
#include <time.h>

using namespace std; 

class Question {
	private:
		vector<string> *q_vector;
		list<string> *q_list;

	public:	
		Question(): q_vector(new vector<string>), q_list(new list<string>){}

		~Question(){
			delete q_vector;
			delete q_list;
		}
		
		int get_vsize() const{return q_vector->size();}
		int get_lsize() const{return q_list->size();}
		string v_elem_at_rank(int r){return q_vector->at(r);}
		string l_elem_at_rank(int r);
		void vec_load(string line, vector<Question>& vec);
		void list_load(string line, vector<Question>& vec);
		bool check_answer_vec(char answer);
		bool check_answer_list(char answer);

		Question(const Question& q): q_vector(new vector<string>), q_list(new list<string>){
			q_vector->resize(q.q_vector->size());
			q_list->resize(q.q_list->size());
			copy(q.q_vector->begin(), q.q_vector->end(), q_vector->begin());
			copy(q.q_list->begin(), q.q_list->end(), q_list->begin());
		}

		Question(Question& q): Question(){
			swap(*this, q);
		}

		Question& operator=(Question q){
			Question temp(q);
			swap(*this, temp);
			return *this;	
		}

		friend void swap(Question& first, Question& second){
			using std::swap;
			swap(first.q_vector, second.q_vector);
			swap(first.q_list, second.q_list);
		}

		bool operator==(const Question& q) const {
			bool equal = true;
			if(this != &q)
				equal = false;
			return equal;
		}	
};

inline std::ostream& operator<<(std::ostream& out, Question& q){
	char choices [5] = {'a', 'b', 'c', 'd', 'e'};
	int count = 0;
	if(q.get_vsize() == 0 && q.get_lsize() != 0){
		for(int i = 0; i <= q.get_lsize()-2; ++i){
			if(i == 0)
				out<< q.l_elem_at_rank(i) << '\n';
			else{
				out<<'\t'<<'('<< choices[count] <<") "<< q.l_elem_at_rank(i) <<'\n';
				++count;
			}	
		}
	}	
	else if(q.get_vsize() != 0 && q.get_lsize() == 0){
		for(int ii = 0; ii <= q.get_vsize()-1; ++ii){
			if(ii == 0)
				out<< q.v_elem_at_rank(ii) << '\n';
			else if(ii == q.get_vsize()-1 && ii != 0)
				out<<'\n';
			else{
				out<<'\t'<<'('<< choices[count] <<") "<< q.v_elem_at_rank(ii) <<'\n';
				++count;
			}
		}
	}
	else
		out<<"This question has not been loaded yet.\n";
	return out;
}