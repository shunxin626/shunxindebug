#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 移除静态全局变量的声明，若无实际用途
// static int i;

class LibrarySystem {
public:
    void home();    // 用户登录界面
    void home01();  
    void home02();  // 辅助用户登录界面
    void enroll();  // 注册
    void ologon();  // 普通用户登录
    void adlogon(); // 管理员登录
};

// 实现 LibrarySystem 成员函数
void LibrarySystem::home() {
    cout << "Welcome to the Library Home Page." << endl;
}

void LibrarySystem::home01() {
    cout << "Welcome to Home Page Version 1." << endl;
}

void LibrarySystem::home02() {
    cout << "Welcome to Home Page Version 2." << endl;
}

void LibrarySystem::enroll() {
    cout << "Enrollment Page." << endl;
}

void LibrarySystem::ologon() {
    cout << "Ordinary User Login Page." << endl;
}

void LibrarySystem::adlogon() {
    cout << "Administrator Login Page." << endl;
}

class Book {
private:
    string title;
    string author;
    string publisher;
    string isbn;
    string category;
    double price;
    string bookID;

public:
    Book(string t, string a, string pub, string i, string cat, double p) 
    : title(t), author(a), publisher(pub), isbn(i), category(cat), price(p) {
        bookID = t + "_" + a;
    }

    void displayInfo() const {
        cout << "Book ID: " << bookID << endl
             << "Title: " << title << endl
             << "Author: " << author << endl
             << "Publisher: " << publisher << endl
             << "ISBN: " << isbn << endl
             << "Category: " << category << endl
             << "Price: $" << price << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        cout << "Library Catalog:" << endl;
        for (const auto& book : books) {
            book.displayInfo();
            cout << endl;
        }
    }
};

int main() {
    LibrarySystem librarySystem;
    librarySystem.home();

    Book book1("Harry Potter", "J.K. Rowling", "Bloomsbury", "9780747532743", "Fantasy", 20.00);
    Book book2("The Lord of the Rings", "J.R.R. Tolkien", "Allen & Unwin", "9780261102385", "Fantasy", 22.00);

    Library lib;
    lib.addBook(book1);
    lib.addBook(book2);
    
    lib.displayAllBooks();

    return 0;
}

int main(){
    // 创建图书馆对象
    Library library;

    // 录入新书籍信息
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "9780743273565", "Fiction", 9.99);
    Book book2("To Kill a Mockingbird", "Harper Lee", "Harper Perennial", "9780061120084", "Classic", 8.99);

    // 将书籍添加到图书馆
    library.addBook(book1);
    library.addBook(book2);

    // 显示所有图书信息
    library.displayAllBooks();
    home();         
    return 0;
}

void home()         //用户登录界面
{
cout << "--------------------------------------------" << endl;
cout << "|         欢迎进入图书管理系统             |"<< endl;
cout << "--------------------------------------------" << endl;
cout << "|              1.用户登录                  |" << endl;
cout << "|                                          |" << endl;
cout << "|              2.用户注册                  |" << endl;
cout << "|                                          |" << endl;
cout << "|              3.退出系统                  |" << endl;
cout << "--------------------------------------------" << endl;         //输出整个菜单界面

cout<<"请输入要选择的功能:"<<endl;          //提示用户输入功能选项
    cin>>i;                                //接收用户输入的选项
    switch(i)                              //根据用户输入的选项进行判断
    {
        case 1:                            //如果用户选择了1
            system("cls");                 //清空屏幕
            home01();                      //调用函数home01()，执行相应的操作
            break;
        case 2:
            system("cls");
            enroll();
            break;
        case 3:
            exit(-1);
            break;
        default:system("cls");
            home();
            cout<<"输入错误,重新输入。"<<endl;
    }
}

void home01()           //登录函数
{
cout << "--------------------------------------------" << endl;
cout << "|            请选择登录身份                |" << endl;
cout << "--------------------------------------------" << endl;
cout << "|           1.管理员登录                   |" << endl;
cout << "|                                          |" << endl;
cout << "|           2.普通用户登录                 |" << endl;
cout << "|                                          |" << endl;
cout << "|           3.返回上一级                   |" << endl;
cout << "--------------------------------------------" << endl;

    cout<<"请输入要选择的功能:"<<endl;
    cin>>i;
    switch(i)
    {
        case 1:
            adlogon();
            break;
        case 2:
            system("cls");
            ologon();
            break;
        case 3:
            system("cls");
            main();
            break;
        default:system("cls");
            home01();                             //调用home函数                              
            cout<<"输入错误,重新输入。"<<endl;
    }
}

void home02()           //普通用户登录后界面选择
{
cout << "--------------------------------------------------" << endl;
cout << "|            欢迎进入图书管理系统                |" << endl;
cout << "--------------------------------------------------" << endl;
cout << "|                1.查询图书                      |" << endl;
cout << "|                                                |" << endl;
cout << "|                2.借阅图书                      |" << endl;
cout << "|                                                |" << endl;
cout << "|                3.归还图书                      |" << endl;
cout << "--------------------------------------------------" << endl;

    cout<<"请输入要选择的功能:"<<endl;
    cin>>i;
    switch(i)
    {
        case 1:
             cout<<"查询图书"<<endl;
            break;
        case 2:
            system("cls");
             cout<<"借阅图书"<<endl;
            break;
        case 3:
            system("cls");
            cout<<"归还图书"<<endl;
            break;
        default:system("cls");
            home01();                           //调用home函数 
            cout<<"输入错误,重新输入。"<<endl;
    }
}


void enroll()           //注册
{
	ofstream ofs ;
	ofs.open("图书管理注册名单.txt",ios::out|ios::app|ios::ate);
	if(!ofs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
	string name;
	string password;

	cout<<"请输入用户名名称: ";
	cin>>name;
	cout<<"请输入密码: ";
	cin>>password;
    ofs<<name<<" "<<password<<endl;
	cout<<"注册成功！"<<endl;
	ofs.close();

	main();
}

void ologon()           //普通用户登录
{
	ifstream ifs ;
	ifs.open("图书管理注册名单.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
	string name;
	string password;
	string line;

    cout<<"请输入用户名名称: ";
    cin>>name;
    cout<<"请输入密码:";
    cin>>password;


    while(getline(ifs,line))                                //循环读取文件中的每一行
	{

			size_t blank=line.find(' ');                    //查找空格位置

			string savename=line.substr(0,blank);           //获取用户名
			string savepassword=line.substr(blank+1);

			if(savepassword==password && savename==name)
			{
				cout<<"登录成功"<<endl;
                home02();
			}
			else
			{
			    system("cls");
				cout<<"密码错误"<<endl;
				home01();
			}

	}
}

void adlogon()          //管理员登录
{
    cin.get();
	ifstream ifs ;
	ifs.open("图书管理员名单.txt",ios::in);
	if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
	string name;
	string password;
	string temp;

    cout<<"请输入您的名字名称: ";
    getline(cin,name);

    while(getline(ifs,temp))
	{
		if(temp==name)          //如果匹配用户名成功
		{
			cout<<"请输入密码:";
			getline(cin,password);
			getline(ifs,temp);          //匹配用户名
			if(temp==password)
			{
				cout<<"进入管理员界面"<<endl;

			}
			else
			{
			    system("cls");
				cout<<"密码错误"<<endl;
				home01();
			}
		}
	}
}
