#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void creategroup(string& groupname,string groups[],int& groupcount){
    cout<<"Enter group name:";
    cin.ignore();
    getline(cin,groupname);
    ofstream file("Groups.txt",ios::app);
    if(!file.is_open()){
    	cerr<<"Error.Unable to initialize group file."<<endl;
    	return;
    }
        file<<"Group Name:"<<groupname<<endl;
        file.close();
        groups[groupcount++]=groupname;
        cout<<"Group created and file initialized."<<endl;
}

void addmembertogroup(string groups[],int groupcount,string members[][2],int& membercount){
	    if(groupcount==0){
        cout<<"No groups available.Create a group first."<<endl;
        return;
    }
    cout<<"Available groups:"<<endl;
    for(int i=0;i<groupcount;++i){
        cout<<i+1<<"."<<groups[i]<<endl;
    }
    int groupChoice;
    cout<<"Select a group by number:";
    cin>>groupChoice;
    if(groupChoice<1 || groupChoice>groupcount){
        cout<<"Invalid group selection."<<endl;
        return;
    }
    string groupname=groups[groupChoice-1];
    cin.ignore();
    string memberName,memberEmail;
    cout<<"Enter member name:";
    getline(cin,memberName);
    cout<<"Enter member email:";
    getline(cin,memberEmail);
    members[membercount][0]=memberName;
    members[membercount][1]=memberEmail;
    membercount++;
    ofstream file("Groups.txt",ios::app); 
    if(!file.is_open()){
        cerr<<"Error.Unable to open file to save member."<<endl;
        return;
    }
    file<<"Name:"<<memberName<<", Email:"<<memberEmail 
         <<" (Group:"<<groupname<<")"<<endl;
    file.close();
    cout<<"Member added to group "<<groupname<<" and saved to file."<<endl;
}

void addexpense(string members[][2],int membercount, double memberExpenses[]){
    if(membercount==0){
        cout<<"No members available.Add members first."<<endl;
        return;
    }
    double totalexpense;
    cout<<"Enter total expense amount:";
    cin>>totalexpense;
    cout<<"Available members:"<<endl;
    for(int i=0;i<membercount;i++){
        cout<<i+1<<"."<<members[i][0]<<"("<<members[i][1]<<")"<<endl;
    }
    int memberindices[100];
    int numselected;
    cout<<"How many members will contribute to this expense?";
    cin>>numselected;
    for(int i=0;i<numselected;i++){
        cout<<"Enter the number corresponding to the member:";
        cin>>memberindices[i];
        if(memberindices[i]<1 || memberindices[i]>membercount){
            cout<<"Invalid member selection.Try again."<<endl;
            i--;
        }
    }
    char splitchoice;
    cout<<"Split expense choice(E for equally,U for unequally):";
    cin>>splitchoice;
    switch(splitchoice){
    	case 'E':
    	case 'e':
    	{
        double share=totalexpense/numselected;
        for(int i=0;i<numselected;i++){
            memberExpenses[memberindices[i]-1] += share;
            cout<<members[memberindices[i]-1][0]<<" pays:"<<share<<endl;
        }
        break;
    }
    case 'U':
    case 'u':
    {
        double amounts[100];
        double totalassigned = 0;
        for(int i=0;i<numselected;i++){
            cout<<"Enter amount for "<<members[memberindices[i]-1][0]<<":";
            cin>>amounts[i];
            totalassigned+=amounts[i];
        }
        if (totalassigned != totalexpense) {
            cout<<"Assigned amounts do not equal total expense."<<endl;
        }else{
            for(int i=0;i<numselected;i++){
                memberExpenses[memberindices[i]-1] += amounts[i];
                cout<<members[memberindices[i]-1][0]<<" pays:"<<amounts[i]<<endl;
            }
        }
        break;
    }
    default:
    	  cout<<"Invalid input."<<endl;
    }
}

void showgroupsummary(string groups[], int groupcount, string members[][2], int membercount, double memberExpenses[]){
    if(groupcount==0){
        cout<<"No groups available."<<endl;
        return;
    }
    cout<<"Group Summary:"<<endl;
    for(int i=0;i<groupcount;i++){
        cout<<"Group "<<i+1<<": "<<groups[i]<<endl;
        cout<<"Members:"<<endl;
        for(int j=0;j<membercount;j++){
            cout<<"- "<<members[j][0]<<" ("<<members[j][1]<<") owes $"<<memberExpenses[j]<<endl;
        }
    }
}

bool checkcredentials(string& email,string& password){
	string fileemail,filepassword;
	ifstream file("credentials.txt");
	if(!file.is_open()){
		cerr<<"File not open."<<endl;
		return false;
	}
	while(getline(file,fileemail) && getline(file,filepassword)){
		if(fileemail==email){
			return filepassword==password;
		}
	}
	return false;
}

bool addnewuser(string& email,string& password){
	ofstream file("credentials.txt",ios::app);
	if(!file.is_open()){
		cerr<<"File not open."<<endl;
		return false;
	}else{
		file<<email<<endl<<password<<endl;
		return true;
	}
}

int main(){
    string groups[100],members[1000][2]; 
    double memberExpenses[1000] = {0};
    int membercount=0,groupcount=0,Choice;
	char choice;
	string email,password,groupname;
	cout<<"Enter choice(L for login and S for sign in):";
	cin>>choice;
	switch(choice){
		case 'L':
		case 'l':
			cout<<"Enter your email:";
			cin>>email;
			cout<<"Enter your password:";
			cin>>password;
			if(checkcredentials(email,password)){
				cout<<"Log in successful."<<endl;
			}else{
				cout<<"Invalid email or password."<<endl;
				return 0;
			}
			break;
		case 'S':
		case 's':
			cout<<"Enter new email:";
			cin>>email;
			cout<<"Enter new password:";
			cin>>password;
			if(addnewuser(email,password)){
				cout<<"User successfully added."<<endl;
			}else{
				cout<<"Sign in failed."<<endl;
			}
			break;
		default:
		    cout<<"Invalid input."<<endl; 	
	}
	while(true){
	cout<<"1. Create Group."<<endl;
	cout<<"2. Add member."<<endl;
	cout<<"3. Add expenses."<<endl;
	cout<<"4. Show Group Summary."<<endl;
	cout<<"5. Exit."<<endl;
	cout<<"Enter your choice:";
	cin>>Choice;
	switch(Choice){
		case 1:
		  creategroup(groupname,groups,groupcount);
		  break;
		case 2:
		  addmembertogroup(groups,groupcount,members,membercount);
		  break;
		case 3:
			addexpense(members,membercount,memberExpenses);
			break;
		case 4:
			showgroupsummary(groups,groupcount,members,membercount,memberExpenses);
			break;
		case 5:
			cout<<"Exitting program."<<endl;
			return 1;
		default:
			cout<<"Invalid input."<<endl;
	}
}
}