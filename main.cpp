#include "Question.h"
using namespace std; 

int main(){
	Question questions;
	vector<Question> quiz;
	
	srand(time(NULL));

	cout<<"Please enter the name of the file you would like to use for this quiz (Database.txt): ";  
	string file_name;
	cin>>file_name; 

	string line;
	string data_type; 

	fstream load_data;
	load_data.open(file_name);
	if(!load_data){
		throw runtime_error("Cannot Open File");  
	}

	cout<<"What type of datastructure would you like to use? vector (0) or list(1)?: "; 
	cin>>data_type;

	char state;
	if (data_type == "1"||data_type =="list"){
		state = 'l';
		while(getline(load_data, line)){ 
			questions.list_load(line, quiz);	
		}
		load_data.close();
	}
	else if(data_type == "0"|| data_type =="vector"){
		state = 'v';
		while(getline(load_data, line)){
			questions.vec_load(line, quiz); 
		}
		load_data.close();
	}
	else{
		throw runtime_error("That is not a valid input.");
	}

	int score = 0;
	int count;
	char answer;
	int myints[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	list<int> random_ints (myints, myints + 15); 

	int current_q;
	for(int i = 1; i <= 10; ++i){
		current_q = rand() % random_ints.size();
		count = 0;
		for(list<int>::iterator it = random_ints.begin(); it != random_ints.end(); ++it){
			if(count == current_q){
				current_q = *it;
			}	
			else
				++count;
		}
		random_ints.remove(current_q);
		cout<<endl;

		cout<<"Question Number: "<<i<<endl;
		cout<<quiz[current_q]<<endl;

		cout<<"Please enter your answer: ";
		cin>>answer;
		
		if(state == 'v'){
			if(quiz[current_q].check_answer_vec(answer) == true){
				score +=10;
				cout<<"Correct! Your score is now: "<<score<<endl;
			}	
			else
				cout<<"Incorrect. Your score is currently: "<<score<<endl;
		}
		else if(state == 'l'){
			if(quiz[current_q].check_answer_list(answer) == true){
				score +=10;
				cout<<"Correct! Your score is now: "<<score<<endl;
			}	
			else
				cout<<"Incorrect. Your score is currently: "<<score<<endl;
		}	
	}
	
	if (score >=70){
		cout<<"Nice job Your final score is: "<<score<<". You passed!"<<endl; 
	}
	else{
		cout<<"Sorry your score is: "<<score<<". You failed. Try again!"<<endl; 
	}
	return 0;
}