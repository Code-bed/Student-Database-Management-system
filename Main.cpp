#include <iostream>
#include "Student.h"
#include "Taken_Course.h"
#include "Sorted_Doubly_Linked_List.h"
#include "Node.h"
#include "BTreeAll.h"
#include "BtreeKey.h"
#include "BTreeNode.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int order_of_btree;
	BTree t;
	Sorted_Doubly_Linked_List sdll;
	int ch1;
	cout<<"	     <---------   DataBase System    ------->    \n\n";
	cout<<"1 ) Load Database from an existing file\n2 ) Create a new Database\n\nEnter Option : ";
	cin>>ch1;
	if (ch1 == 1)
	{
		ifstream infile("data.txt");
		string rder;
		getline(infile, rder);
		int order = stoi(rder);
		order_of_btree = order;
		string line;
		t.set_order(order);
		while (getline(infile, line))
		{
			vector<Taken_Course*> courses;
			istringstream iss(line);
			vector<string> words;
			while (getline(iss, line, ' '))
				words.push_back(line);
			int roll_number=stoi(words[0]);
			string name = words[1]+ " " + words[2];
		
			for (int i=3;i<words.size();i++)
			{
				string course_name = words[i];
				string grade = words[i+1];
				i+=1;
				Taken_Course* c = new Taken_Course(course_name,grade);
				courses.push_back(c);
			}
			Student* s = new Student(roll_number,name,courses);
			node* n;
			n = sdll.create(s);
			t.insert(roll_number,n);
			
		}
		//sdll.ascending();
		infile.close();
	}
	else
	{
		// create you own database
		int order;
		cout<<"Set the order of B-tree : ";
		cin>>order;
		order_of_btree = order;
		t.set_order(order);
		int choice = 1;
		while (choice == 1)
		{			
			cout<<"1 Ali Asgher CS101 B- CS102 D MT110 A EE101 B-   ( Example Record )\n";
			cout<<"Enter the record in the above mentioned format : \n";
			char inputarr[200];
			int index = 0;
			char input;
			cin.ignore();
			do {
				input=getchar();
				inputarr[index++] = input;
			} while (input != '\n');
			inputarr[index] = '\0';
			string record(inputarr);
			//cout<<record;
			istringstream iss(record);
			vector<Taken_Course*> courses;
			vector<string> words;
			while (getline(iss, record, ' '))
				words.push_back(record);
			int roll_number=stoi(words[0]);
			string name = words[1]+ " " + words[2];
		
			for (int i=3;i<words.size();i++)
			{
				string course_name = words[i];
				string grade = words[i+1];
				i+=1;
				Taken_Course* c = new Taken_Course(course_name,grade);
				courses.push_back(c);
			}
			Student* s = new Student(roll_number,name,courses);
			node* n;
			n = sdll.create(s);
			t.insert(roll_number,n);

			cout<<"\nDo You Want to Insert Another Record ? (Yes == 1,No == 0) : ";
			cin>>choice;
		}

	}
	while (true)
	{
		cout<<"	     <---------   Operations    ------->    \n\n";
		cout<<"1 ) Create Record \n2 ) Read Record \n3 ) Delete Record\n4 ) Update Record \n5 ) View All Records\n6 ) Records in a Range(Ascending) \n7 ) Records in a Range(Descending)\n8 ) Save to File \n\nEnter Option : ";
		cin>>ch1;
		if (ch1 == 1){
			
			cout<<"1 Ali Asgher CS101 B- CS102 D MT110 A EE101 B-   ( Example Record )\n";
			cout<<"Enter the record in the above mentioned format : \n";
			char inputarr[200];
			int index = 0;
			char input;
			cin.ignore();
			do {
				input=getchar();
				inputarr[index++] = input;
			} while (input != '\n');
			inputarr[index] = '\0';
			string record(inputarr);
			//cout<<record;
			istringstream iss(record);
			vector<Taken_Course*> courses;
			vector<string> words;
			while (getline(iss, record, ' '))
				words.push_back(record);
			int roll_number=stoi(words[0]);
			string name = words[1]+ " " + words[2];
		
			for (int i=3;i<words.size();i++)
			{
				string course_name = words[i];
				string grade = words[i+1];
				i+=1;
				Taken_Course* c = new Taken_Course(course_name,grade);
				courses.push_back(c);
			}
			Student* s = new Student(roll_number,name,courses);
			node* n;
			n = sdll.create(s);
			t.insert(roll_number,n);
		}
		else if (ch1 == 5)
		{
			sdll.ascending();
		}
		else if (ch1 == 2)
		{
			int r;
			cout<<"Enter the Roll Number of the student : ";
			cin>>r;
			(t.search(r) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
			if (t.search(r) != NULL)
			{
				node* found_record = t.search(r);
				found_record->student->print();
			}
		}
		else if (ch1==3)
		{
			int r;
			cout<<"Enter the Roll Number of the student : ";
			cin>>r;
			t.remove(r);
			sdll.delete_student(r);
		}
		else if (ch1==6)
		{
			int r1;
			cout<<"Enter Starting RollNo : ";
			cin>>r1;
			int r2;
			cout<<"Enter Ending RollNo : ";
			cin>>r2;
			cout<<endl;
			for (int i=r1;i<=r2;i++)
			{
				if (t.search(i) != NULL)
				{
					node* found_record = t.search(i);
					found_record->student->print();
				}
			}
		}
		else if (ch1==7)
		{
			int r1;
			cout<<"Enter Starting RollNo : ";
			cin>>r1;
			int r2;
			cout<<"Enter Ending RollNo : ";
			cin>>r2;
			cout<<endl;
			for (int i=r2;i>=r1;i--)
			{
				if (t.search(i) != NULL)
				{
					node* found_record = t.search(i);
					found_record->student->print();
				}
			}



		}
		else if(ch1==4)
		{
			int r;
			cout<<"Enter the Roll Number of the student : ";
			cin>>r;
			(t.search(r) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
			if (t.search(r) != NULL)
			{
				node* found_record = t.search(r);
				found_record->student->print();
			}




			cout<<"Ali Asgher CS101 B- CS102 D MT110 A EE101 B-   ( Example Record )\n";
			cout<<"Enter the record in the above mentioned format : \n";
			char inputarr[200];
			int index = 0;
			char input;
			cin.ignore();
			do {
				input=getchar();
				inputarr[index++] = input;
			} while (input != '\n');
			inputarr[index] = '\0';
			string record(inputarr);
			//cout<<record;
			istringstream iss(record);
			vector<Taken_Course*> courses;
			vector<string> words;
			while (getline(iss, record, ' '))
				words.push_back(record);
			int roll_number=r;
			string name = words[0]+ " " + words[1];
		
			for (int i=2;i<words.size();i++)
			{
				string course_name = words[i];
				string grade = words[i+1];
				i+=1;
				Taken_Course* c = new Taken_Course(course_name,grade);
				courses.push_back(c);
			}
			Student* s = new Student(roll_number,name,courses);
			node* n;

			t.remove(r);
			sdll.delete_student(r);

			n = sdll.create(s);
			t.insert(roll_number,n);










		}

		else if (ch1==8)
		{
			ofstream fout("student_data.txt");
			fout<<order_of_btree<<endl;
			node* t = sdll.head;
			string record = "";
			while(t!=NULL)
			{
				fout<<t->student->get_roll_number()<<" "<<t->student->name<<" ";
				for(Taken_Course* i : t->student->courses_taken)
				{
					fout<<i->course_name<<" "<<i->grade;
				}
				fout<<endl;
				t=t->next;
			}
		}
		else
		{
			cout<<"Wrong Option Selected \n";
		}
	}
//	cout << "Traversal of the constucted tree is ";
//	t.traverse();
//	
//	int k = 20;
//	(t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
//	if (t.search(k) != NULL)
//	{
//		node* found_record = t.search(k);
//		found_record->student->print();
//	}
//	
//	t.remove(20);
//	sdll.delete_student(20);
//	t.traverse();
//	cout<<endl;
////	sdll.delete_student(20);
	
	cout<<endl;

	return 0;
}