#include<iostream> 
#include<fstream>
#include<string>
using namespace std; 
#define M 200   //可以存信息总量
int N=0;  //学生总量  
class student
{ 
public: 
	student(); 
	void set(student& s);       //初始化信息，第一次对信息的录入 
	void add(student& s);       //添加学生信息 
	void del(student& s);       //删除某学生信息 
	void change(student& s);    //修改某学生信息   
	void search(student& s);    //查询某学生信息 
	void sort(student& s);      //排序
	void count(student& s);      //统计
	void display(student& s);   //显示全部学生信息
private: 
	int id,age,java;
	string name,sex; 
}; 

student::student() {} 

void student::set(student& s)
{ 
	ofstream outfile;
	outfile.open("f1.txt",ios::out);   //----打开文件---- 
	if(!outfile) 
	{  
		cerr<<" open error"<<endl;   
		exit(1); 
	}  //----依次录入相应个数的学生信息----  
	for(int i=0;i<M;i++)     //可以存信息总量
	{  
		cout<<"当姓名输入为'0'时，停止输入！！！"<<endl;
		cout<<"请输入姓名："<<endl;  
		cin>>s.name; 
		if (s.name == "0") break;  
		if (s.name != "0")  
		{ 
			N++;    //学生总量  
			cout << "请输入学号：" << endl;
			cin >> s.id;
			outfile << s.id << "  ";      
			outfile << s.name << "  ";  
			cout << "请输入性别：" << endl;    
			cin >> s.sex;        
			outfile << s.sex << "  ";     
			cout << "请输入年龄：" << endl;    
			cin >> s.age;   
			outfile << s.age << "  ";   
			cout << "请输入java成绩：" << endl;   
			cin >> s.java;    
			outfile << s.java << endl;
		} 
	}  
	outfile.close();    //----关闭文件---- 
}

void student::add(student& s)
{ 
	ofstream outfile("f1.txt",ios::app);  //以追加的方式录入信息，直接将信息追加到以前文件的末尾
	if(!outfile)   
	{  
		cerr<<" open error"<<endl;  
		exit(1);  
	} 
	N=N+1;  //学生总量 ----依次输入相应的数据，并且追加到之前的文件中去---- 
	cout<<"请输入您要添加的数据"<<endl; 
	cout << "请输入学号:" << endl;
	cin >> s.id;
	outfile<<s.id<<"  ";   
	cout<<"请输入姓名："<<endl; 
	cin>>s.name; 
	outfile << s.name << "  "; 
	cout << "请输入性别：" << endl; 
	cin >> s.sex;
	outfile << s.sex << "  ";  
	cout << "请输入年龄：" << endl;  
	cin >> s.age; 
	outfile << s.age << "  "; 
	cout << "请输入java成绩：" << endl; 
	cin >> s.java; 
	outfile << s.java << endl; 
	outfile.close();  
	cout << "已添加成功！" << endl;
} 

void student::del(student& s) {
	int k, i;
	int id[M], age[M], java[M];
	string name[M], sex[M];
	ifstream infile("f1.txt", ios::in);
	if (!infile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	cout << "学号\t\t姓名\t\t性别\t年龄\tjava\t序号" << endl;
	for (i = 0; i<N;)
	{	
		infile >> id[i];
		cout << id[i];
		infile >> name[i];
		cout << "\t\t" << name[i];
		infile >> sex[i];
		cout << "\t\t" << sex[i];
		infile >> age[i];
		cout << "\t" << age[i];
		infile >> java[i];
		cout << "\t" << java[i];
		cout << "\t" << ++i << endl;
	}
	cout << "你想删除第几个？" << endl;
	cin >> k;
	k = k - 1;
	infile.close();
	ofstream outfile("f1.txt", ios::out);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1); //退出程序 
	}  //----将数组存取的信息输出到文件中去---- 
	for (i = 0; i<N; i++)
	{
		if (i != k)
		{
			outfile << id[i] << "   ";
			outfile << name[i] << "   ";
			outfile << sex[i] << "   ";
			outfile << age[i] << "   ";
			outfile << java[i] << "   " << endl;
		}
	}
	outfile.close();
	N = N - 1;
	cout << "已删除成功！" << endl;
}

void student::change(student& s)
{ 
	string name[M], sex[M];
	int i,k,id[M],age[M], java[M];
	ifstream infile("f1.txt",ios::in); 
	if(!infile) 
	{ 
		cerr<<" open error"<<endl;
		exit(1); 
	}
	cout << "学号\t\t姓名\t\t性别\t年龄\tjava\t序号" << endl;
	for (i = 0; i<N;)
	{
		infile >> id[i];
		cout << id[i];
		infile >> name[i];
		cout << "\t\t" << name[i];
		infile >> sex[i];
		cout << "\t\t" << sex[i];
		infile >> age[i];
		cout << "\t" << age[i];
		infile >> java[i];
		cout << "\t" << java[i];
		cout << "\t" << ++i << endl;
	}
	infile.close(); 
	ofstream outfile("f1.txt", ios::out);
	if (!outfile)   
	{ 
		cerr << " open error" << endl;  
		exit(1);
	} 
	cout << "你想修改第几个数据?" << endl;
	cin >> k; 
	k = k - 1; 
	cout << "请输入新的数据：" << endl;  
	cout << "请输入学号：" << endl;
	cin >> id[k];
	cout << "请输入姓名：" << endl; 
	cin >> name[k];
	cout << "请输入性别：" << endl; 
	cin >> sex[k]; 
	cout << "请输入年龄：" << endl; 
	cin >> age[k];
	cout << "请输入java成绩：" << endl; 
	cin >> java[k]; 
	for (i = 0; i<N; i++) 
	{
		outfile << id[i] << "   ";  
		outfile << name[i] << "   "; 
		outfile << sex[i] << "   "; 
		outfile << age[i] << "   ";  
		outfile << java[i] << "   " << endl;
	} 
	outfile.close();
	cout << "已修改成功！" << endl;
}

void student::search(student& s)
{
	int i, n, w = 0, id[M], a[M];
	char ch; 
	string searchname, name[M], sex[M], age[M], java[M], b[M][4];  
	cout << "a.按学号查找    b.按姓名查找" << endl; 
	ifstream infile("f1.txt", ios::in); 
	if (!infile)
	{
		cerr << " open error" << endl;  
		exit(1);
	} 
	for (i = 0; i<N; i++) 
	{
		infile >> id[i];
	    a[i] = id[i]; 
	    infile >> name[i]; 
	    b[i][0] = name[i];  
	    infile >> sex[i]; 
	    b[i][1] = sex[i];  
	    infile >> age[i];
	    b[i][2] = age[i]; 
	    infile >> java[i]; 
	    b[i][3] = java[i]; 
	}  
	cout << "请输入a或者b!" << endl;  
	cin >> ch; 
	if (ch == 'a') 
	{ 
		cout << "请输入学号！" << endl;
		cin >> n;  
		for (i = 0; i<N; i++)  
			if (a[i] == n)    
			{ 
				w = 1;  
				cout << "学号\t\t姓名\t\t性别\t年龄\tjava" << endl;  
				cout << a[i];
				cout << "\t\t" << b[i][0];
				cout << "\t\t" << b[i][1];
				cout << "\t" << b[i][2];
				cout << "\t" << b[i][3] << endl;
			} 
		if (w == 0)  
			cout << "无此人信息！" << endl;
	}
	else if (ch == 'b')  
	{
		cout << "请输入姓名！" << endl; 
		cin >> searchname;  
		for (i = 0; i<N; i++)  
			if (name[i] == searchname)  
			{
				w = 1;   
				cout << "学号\t\t姓名\t\t性别\t年龄\tjava" << endl;
				cout << a[i];
				cout << "\t\t" << b[i][0];
				cout << "\t\t" << b[i][1];
				cout << "\t" << b[i][2];
				cout << "\t"<< b[i][3] << endl;
		}    
		if (w == 0)    
			cout << "无此人信息！" << endl;
	}
	else
		cout << "没有此选项！" << endl;
}  
void quiksort(int a[], int low, int high)  //快速排序
{
	int i = low;
	int j = high;
	int temp = a[i];

	if (low < high)
	{
		while (i < j)
		{
			while ((a[j] >= temp) && (i < j))
			{
				j--;
			}
			a[i] = a[j];
			while ((a[i] <= temp) && (i < j))
			{
				i++;
			}
			a[j] = a[i];
		}
		a[i] = temp;
		quiksort(a, low, i - 1);
		quiksort(a, j + 1, high);
	}
	else
	{
		return;
	}
}
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}
bool MergeSort(int a[], int n)   //归并排序
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
} 

void student::sort(student& s)
{
	string name[M], sex[M], st[M][2];
	int i, k, id[M], age[M], java[M], a[M], b[M][2];
	char ch;
	ifstream infile("f1.txt", ios::in);
	if (!infile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	for (i = 0; i<N; i++)
	{
		infile >> id[i];
		b[i][0] = id[i];   //b[i][0]存放学号
		infile >> name[i];
		st[i][0] = name[i];
		infile >> sex[i];
		st[i][1] = sex[i];
		infile >> age[i];
		b[i][1] = age[i];
		infile >> java[i];
		a[i] = java[i];
	}
	infile.close();
	ofstream outfile("f1.txt", ios::out);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	cout << "a.快速排序    b.归并排序" << endl;
	cout << "请输入a或者b!" << endl;
	cin >> ch;
	if (ch == 'a')
		quiksort(a, 0, N - 1);
	else
		MergeSort(a, N); //a已经排好  从小到大    
	for (k = 0; k<N; k++)
	{
		for (i = 0; i<N; i++)
			if ((a[k] == java[i]))
			{
				id[i] = b[i][0];
				name[i] = st[i][0];
				sex[i] = st[i][1];
				age[i] = b[i][1];
				outfile << id[i] << "   ";
				outfile << name[i] << "   ";
				outfile << sex[i] << "   ";
				outfile << age[i] << "   ";
				outfile << java[i] << "   " << endl;
			}
	}
	outfile.close();
	cout << "已排好序" << endl;
}

void student::count(student& s)
{
	char ch;
	int c1 = 0; //60分以上的同学人数
	int c2 = 0; //80分以上的同学人数
	ifstream infile("f1.txt", ios::in);
	if (!infile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	cout << "学号\t\t姓名\t\t性别\t年龄\tjava" << endl;
	for (int k = 0; k < N; k++)
	{
		infile >> s.id;
		cout << s.id;
		infile >> s.name;
		cout << "\t\t" << s.name;
		infile >> s.sex;
		cout << "\t\t" << s.sex;
		infile >> s.age;
		cout << "\t" << s.age;
		infile >> s.java;
		cout << "\t" << s.java<<endl;
		if (s.java >= 60)
			c1 = c1 + 1;
		if (s.java >= 80)
			c2 = c2 + 1;
	}
		cout << "a.不及格   b.及格  c.80分以上" << endl;
		cout << "请输入a、b或者c!" << endl;
		cin >> ch;
		if (ch == 'a')
			cout << "不及格" << N - c1 << "人" << endl;
		if (ch == 'b')
			cout << "及格" << c1 << "人" << endl;
		if (ch == 'c')
			cout << "80分以上" << c2 << "人" << endl;
		infile.close();
}

void student::display(student& s)
{
	ifstream infile("f1.txt", ios::in); 
	if (!infile) 
	{ 
		cerr << " open error" << endl; 
		exit(1); 
	} 
	cout << "学号\t\t姓名\t\t性别\t年龄\tjava" << endl;
	for (int k = 0; k<N; k++) 
	{
		infile >> s.id;  
		cout <<s.id;
		infile >> s.name;  
		cout << "\t\t" << s.name;
		infile >>s.sex; 
		cout << "\t\t" << s.sex;
		infile >> s.age;  
		cout << "\t" << s.age;
		infile >> s.java;  
		cout << "\t" << s.java<< endl;
		
	} 
	infile.close();
}
student stu; 
void main() 
{ 
	char ch; 
	void menu();
	menu(); 
	cin >> ch;
	while (ch != '0')
	{ 
		switch (ch)
		{ 
		case '1':stu.set(stu); break;  
		case '2':stu.add(stu); break;  
		case '3':stu.del(stu); break;  
		case '4':stu.change(stu); break;  
		case '5':stu.search(stu); break;
		case '6':stu.display(stu); break; 
		case '7':stu.sort(stu); break;
		case '8':stu.count(stu); break;
		case '0':cout << "退出系统!"; break;  
		default:cout << "没有此选项！" << endl; break;
		}  
		menu(); 
		cin >> ch;
	}
}  
void menu()
{
	cout << "******************" << endl; 
	cout << "*     1.输入     *" << endl; 
	cout << "*     2.添加     *" << endl; 
	cout << "*     3.删除     *" << endl; 
	cout << "*     4.修改     *" << endl; 
	cout << "*     5.查询     *" << endl;  
	cout << "*     6.显示     *" << endl; 
	cout << "*     7.排序     *" << endl;
	cout << "*     8.统计     *" << endl;
	cout << "*     0.退出     *" << endl; 
	cout << "******************" << endl;
}