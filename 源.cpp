#include<iostream> 
#include<fstream>
#include<string>
using namespace std; 
#define M 200   //���Դ���Ϣ����
int N=0;  //ѧ������  
class student
{ 
public: 
	student(); 
	void set(student& s);       //��ʼ����Ϣ����һ�ζ���Ϣ��¼�� 
	void add(student& s);       //���ѧ����Ϣ 
	void del(student& s);       //ɾ��ĳѧ����Ϣ 
	void change(student& s);    //�޸�ĳѧ����Ϣ   
	void search(student& s);    //��ѯĳѧ����Ϣ 
	void sort(student& s);      //����
	void count(student& s);      //ͳ��
	void display(student& s);   //��ʾȫ��ѧ����Ϣ
private: 
	int id,age,java;
	string name,sex; 
}; 

student::student() {} 

void student::set(student& s)
{ 
	ofstream outfile;
	outfile.open("f1.txt",ios::out);   //----���ļ�---- 
	if(!outfile) 
	{  
		cerr<<" open error"<<endl;   
		exit(1); 
	}  //----����¼����Ӧ������ѧ����Ϣ----  
	for(int i=0;i<M;i++)     //���Դ���Ϣ����
	{  
		cout<<"����������Ϊ'0'ʱ��ֹͣ���룡����"<<endl;
		cout<<"������������"<<endl;  
		cin>>s.name; 
		if (s.name == "0") break;  
		if (s.name != "0")  
		{ 
			N++;    //ѧ������  
			cout << "������ѧ�ţ�" << endl;
			cin >> s.id;
			outfile << s.id << "  ";      
			outfile << s.name << "  ";  
			cout << "�������Ա�" << endl;    
			cin >> s.sex;        
			outfile << s.sex << "  ";     
			cout << "���������䣺" << endl;    
			cin >> s.age;   
			outfile << s.age << "  ";   
			cout << "������java�ɼ���" << endl;   
			cin >> s.java;    
			outfile << s.java << endl;
		} 
	}  
	outfile.close();    //----�ر��ļ�---- 
}

void student::add(student& s)
{ 
	ofstream outfile("f1.txt",ios::app);  //��׷�ӵķ�ʽ¼����Ϣ��ֱ�ӽ���Ϣ׷�ӵ���ǰ�ļ���ĩβ
	if(!outfile)   
	{  
		cerr<<" open error"<<endl;  
		exit(1);  
	} 
	N=N+1;  //ѧ������ ----����������Ӧ�����ݣ�����׷�ӵ�֮ǰ���ļ���ȥ---- 
	cout<<"��������Ҫ��ӵ�����"<<endl; 
	cout << "������ѧ��:" << endl;
	cin >> s.id;
	outfile<<s.id<<"  ";   
	cout<<"������������"<<endl; 
	cin>>s.name; 
	outfile << s.name << "  "; 
	cout << "�������Ա�" << endl; 
	cin >> s.sex;
	outfile << s.sex << "  ";  
	cout << "���������䣺" << endl;  
	cin >> s.age; 
	outfile << s.age << "  "; 
	cout << "������java�ɼ���" << endl; 
	cin >> s.java; 
	outfile << s.java << endl; 
	outfile.close();  
	cout << "����ӳɹ���" << endl;
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
	cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava\t���" << endl;
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
	cout << "����ɾ���ڼ�����" << endl;
	cin >> k;
	k = k - 1;
	infile.close();
	ofstream outfile("f1.txt", ios::out);
	if (!outfile)
	{
		cerr << " open error" << endl;
		exit(1); //�˳����� 
	}  //----�������ȡ����Ϣ������ļ���ȥ---- 
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
	cout << "��ɾ���ɹ���" << endl;
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
	cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava\t���" << endl;
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
	cout << "�����޸ĵڼ�������?" << endl;
	cin >> k; 
	k = k - 1; 
	cout << "�������µ����ݣ�" << endl;  
	cout << "������ѧ�ţ�" << endl;
	cin >> id[k];
	cout << "������������" << endl; 
	cin >> name[k];
	cout << "�������Ա�" << endl; 
	cin >> sex[k]; 
	cout << "���������䣺" << endl; 
	cin >> age[k];
	cout << "������java�ɼ���" << endl; 
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
	cout << "���޸ĳɹ���" << endl;
}

void student::search(student& s)
{
	int i, n, w = 0, id[M], a[M];
	char ch; 
	string searchname, name[M], sex[M], age[M], java[M], b[M][4];  
	cout << "a.��ѧ�Ų���    b.����������" << endl; 
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
	cout << "������a����b!" << endl;  
	cin >> ch; 
	if (ch == 'a') 
	{ 
		cout << "������ѧ�ţ�" << endl;
		cin >> n;  
		for (i = 0; i<N; i++)  
			if (a[i] == n)    
			{ 
				w = 1;  
				cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava" << endl;  
				cout << a[i];
				cout << "\t\t" << b[i][0];
				cout << "\t\t" << b[i][1];
				cout << "\t" << b[i][2];
				cout << "\t" << b[i][3] << endl;
			} 
		if (w == 0)  
			cout << "�޴�����Ϣ��" << endl;
	}
	else if (ch == 'b')  
	{
		cout << "������������" << endl; 
		cin >> searchname;  
		for (i = 0; i<N; i++)  
			if (name[i] == searchname)  
			{
				w = 1;   
				cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava" << endl;
				cout << a[i];
				cout << "\t\t" << b[i][0];
				cout << "\t\t" << b[i][1];
				cout << "\t" << b[i][2];
				cout << "\t"<< b[i][3] << endl;
		}    
		if (w == 0)    
			cout << "�޴�����Ϣ��" << endl;
	}
	else
		cout << "û�д�ѡ�" << endl;
}  
void quiksort(int a[], int low, int high)  //��������
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
		mergesort(a, first, mid, temp);    //�������
		mergesort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
	}
}
bool MergeSort(int a[], int n)   //�鲢����
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
		b[i][0] = id[i];   //b[i][0]���ѧ��
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
	cout << "a.��������    b.�鲢����" << endl;
	cout << "������a����b!" << endl;
	cin >> ch;
	if (ch == 'a')
		quiksort(a, 0, N - 1);
	else
		MergeSort(a, N); //a�Ѿ��ź�  ��С����    
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
	cout << "���ź���" << endl;
}

void student::count(student& s)
{
	char ch;
	int c1 = 0; //60�����ϵ�ͬѧ����
	int c2 = 0; //80�����ϵ�ͬѧ����
	ifstream infile("f1.txt", ios::in);
	if (!infile)
	{
		cerr << " open error" << endl;
		exit(1);
	}
	cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava" << endl;
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
		cout << "a.������   b.����  c.80������" << endl;
		cout << "������a��b����c!" << endl;
		cin >> ch;
		if (ch == 'a')
			cout << "������" << N - c1 << "��" << endl;
		if (ch == 'b')
			cout << "����" << c1 << "��" << endl;
		if (ch == 'c')
			cout << "80������" << c2 << "��" << endl;
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
	cout << "ѧ��\t\t����\t\t�Ա�\t����\tjava" << endl;
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
		case '0':cout << "�˳�ϵͳ!"; break;  
		default:cout << "û�д�ѡ�" << endl; break;
		}  
		menu(); 
		cin >> ch;
	}
}  
void menu()
{
	cout << "******************" << endl; 
	cout << "*     1.����     *" << endl; 
	cout << "*     2.���     *" << endl; 
	cout << "*     3.ɾ��     *" << endl; 
	cout << "*     4.�޸�     *" << endl; 
	cout << "*     5.��ѯ     *" << endl;  
	cout << "*     6.��ʾ     *" << endl; 
	cout << "*     7.����     *" << endl;
	cout << "*     8.ͳ��     *" << endl;
	cout << "*     0.�˳�     *" << endl; 
	cout << "******************" << endl;
}