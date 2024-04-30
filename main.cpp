#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;                  //声明一个静态的全局变量

class LibrarySystem {
private:
    static int i; 

public:
    void home();    // 用户登录界面
    void home01();  
    void home02();  // 辅助用户登录界面
    void enroll();  // 注册
    void ologon();  // 普通用户登录
    void adlogon(); // 管理员登录
};


void LibrarySystem::home() {
    // 实现用户登录界面
}

void LibrarySystem::home01() {
    // 实现用户登录界面
}

void LibrarySystem::home02() {
    // 实现辅助用户登录界面
}

void LibrarySystem::enroll() {
    // 实现注册功能
}

void LibrarySystem::ologon() {
    // 实现普通用户登录功能
}

void LibrarySystem::adlogon() {
    // 实现管理员登录功能
}

int main() {
    LibrarySystem librarySystem;

    // 在这里调用类的成员函数来执行相应的操作

    return 0;
}
// Book 类表示图书信息
class Book {
private:
    string title;
    string author;
    string publisher;
    string isbn;
    string category;
    double price;
    string bookID; // 图书编号

public:
    // 构造函数
    Book(string t, string a, string pub, string i, string cat, double p) : title(t), author(a), publisher(pub), isbn(i), category(cat), price(p) {
        // 生成唯一的图书编号:书名和作者拼接作为编号
        bookID = t + "_" + a;
    }

    // 显示图书信息
    void displayInfo() {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Category: " << category << endl;
        cout << "Price: $" << price << endl;
    }
};

// Library 类表示图书馆，包含图书列表和图书管理功能
class Library {
private:
    vector<Book> books; // 图书列表

public:
    // 添加图书
    void addBook(Book book) {
        books.push_back(book);
    }

    // 显示所有图书信息
    void displayAllBooks() {
    cout << "Library Catalog:" << endl;
    for (const auto& book : books) {
        book.displayInfo(); // 使用 book 对象来调用 displayInfo() 函数
        cout << endl;
    }
}

};

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
