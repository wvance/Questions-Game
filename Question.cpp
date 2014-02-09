#include "Question.h"
using namespace std;

bool Question::check_answer_vec(char answer){
	char correct_answer;
	if(q_vector->at(q_vector->size() - 1) == "a")
		correct_answer = 'a';
	if(q_vector->at(q_vector->size() - 1) == "b")
		correct_answer = 'b';
	if(q_vector->at(q_vector->size() - 1) == "c")
		correct_answer = 'c';
	if(q_vector->at(q_vector->size() - 1) == "d")
		correct_answer = 'd';
	if(q_vector->at(q_vector->size() - 1) == "e")
		correct_answer = 'e';

	if(answer == correct_answer)
		return true;
	else
		cout<<"Correct Answer: "<<q_vector->at(q_vector->size() - 1)<<endl;
		return false;
}

bool Question::check_answer_list(char answer){
	char correct_answer;
	string i = l_elem_at_rank(q_list->size()-1);
	if(i == "a")
		correct_answer = 'a';
	if(i == "b")
		correct_answer = 'b';
	if(i == "c")
		correct_answer = 'c';
	if(i == "d")
		correct_answer = 'd';
	if(i == "e")
		correct_answer = 'e';
	
	if(answer == correct_answer)
		return true;
	else{
		cout<<"Correct Answer: "<<i<<endl;
		return false;
	}	
}

void Question::list_load(string line, vector<Question>& vec){
	if(line.length() == 0 || line == "\n"){
		Question Q;
		for(list<string>::iterator i = q_list->begin(); i != q_list->end(); ++i){
			Q.q_list->insert(Q.q_list->end(), *i);
		}
		vec.push_back(Q);
		q_list->clear();
	}
	else{
		q_list->insert(q_list->end(), line);
	}
}

void Question::vec_load(string line, vector<Question>& vec){
	if(line.length() == 0 || line == "\n"){
		Question Q;
		for(int i = 0; i <= q_vector->size() - 1; ++i){
			Q.q_vector->push_back(q_vector->at(i));
		}
		vec.push_back(Q);
		q_vector->clear();
	}
	else{
		q_vector->push_back(line);
	}	
}

string Question::l_elem_at_rank(int r){
	int count = 0;
	for(list<string>::iterator i = q_list->begin(); i != q_list->end(); ++i){
		if(count == r)
			return *i;
		else
			++count;
	}
}