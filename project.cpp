#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book
{
    string isbn;
    string title;
    string subject;
    string author;
    string publisher;
    string date;
    int pages;
    int copies;
};

struct User
{
    int userid;
    string username;
    string password;
    string user_type;
};


vector<Book>* books = new vector<Book>();
vector<User>* users = new vector<User>();


void Them_sach()
{
    Book book;
    cout << "ISBN: ";
    cin >> book.isbn;
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, book.title);
    cout << "Chu de : ";
    getline(cin, book.subject);
    cout << "Tac gia : ";
    getline(cin, book.author);
    cout << "Nha xuat ban : ";
    getline(cin, book.publisher);
    cout << "Ngay xuat ban : ";
    getline(cin, book.date);
    cout << "So trang : ";
    cin >> book.pages;
    cout << "So ban  copy: ";
    cin >> book.copies;

    books->push_back(book);
    cout << "Sach da duoc them vao thu vien." << endl;
}


User Dang_Nhap()
{
    User user;

    bool loginSuccess = false;

    do {
        cout << "Ten dang nhap : ";
        cin >> user.username;
        cout << "Mat khau : ";
        cin >> user.password;

        for (const User& u : *users) {
            if (u.username == user.username && u.password == user.password) {

                loginSuccess = true;
                return u;
            }
        }

        cout << "Tai khoan hoac Mat khau khong dung . Vui long nhap lai ." << endl;
       
    } while (!loginSuccess);
    return { -1, "", "", "" };
}
User Dang_Nhapuser()
{
    User user;
 
    cout << "Ten nguoi dung : ";
    cin >> user.username;

    bool loginSuccess = false;

    do {
        for (const User& u : *users) {
            if (u.username == user.username ) {

                loginSuccess = true;
                cout << "Dang nhap thanh cong " << endl;
                 cout << "Nguoi dung chi duoc xem thong tin sach trong thu vien." << endl;
                ifstream file;
                char data;

                        file.open("D://books.txt",ios::out);
                        while(file.get(data))
		                    cout<<data;
   	                        file.close();
                return u;
            }
        }
        cout << "Ten nguoi dung khong chinh sac " << endl;
        Dang_Nhapuser();
        break;
    } while (!loginSuccess);

    return { -1, "", "", "" };
}
void suaten_nguoidung()
{
    string username ;
    cout << "Nhap ten nguoi dung can sua: ";
    cin >> username;
    for (User& u : *users)
    {
        if (u.username == username)
            {
            cout << "Nhap ten nguoi dung moi" << endl;
            cin >> u.username;
            cout << "Thong tin da duoc cap nhat. " << endl;
            return;
        }
    }
    cout << "Khong tim thay ten nguoi dung " << username << endl;
}
void tao_tk()
{
    User user;
    cout << "Ten dang nhap moi : ";
cin >> user.username;


    string password;
        password = " ";
    user.password = password;
    user.userid = users->size() + 1;
    user.user_type = "user";
    users->push_back(user);
    cout << "Nguoi dung da duoc tao thanh cong." << endl;
}


void luu_tt_sach() {
    ofstream file("D://books.txt");

    if (file.is_open())
    {
        for (const Book& book : *books)
{
            file << book.isbn << "," << book.title << "," << book.subject << ","
                 << book.author << "," << book.publisher << "," << book.date << ","
                 << book.pages << "," << book.copies << "\n";
        }
        file.close();
    }
    else
    {
cout << "Khong the mo tep tin de luu danh sach ." << endl;
    }
}


void luu_tt_nguoi_dung()
{
    ofstream file("D://users.txt");

    if (file.is_open())
    {
        for (const User& user : *users) {
                file << user.userid << "," << user.username << "," << user.password << ","
                 << user.user_type << "\n";
        }
        file.close();
    } else
    {
        cout << "Khong the mo tep tin de luu thong tin nguoi dung." << endl;
    }
}


void doc_tt_sach() {
ifstream file("D://books.txt");

    if (file.is_open())
    {
        while (!file.eof())
        {
            Book book;
            getline(file, book.isbn, ',');
            getline(file, book.title, ',');
            getline(file, book.subject, ',');
            getline(file, book.author, ',');
            getline(file, book.publisher, ',');
            getline(file, book.date, ',');
            file >> book.pages;
            file.ignore();
            file >> book.copies;
            file.ignore();

            if (!book.isbn.empty())
            {
                books->push_back(book);
            }
        }
        file.close();
    } else
    {
        cout << "Khong the mo tep tin de luu danh sach ." << endl;
    }
}


void doc_tt_nguoi_dung()
{
    ifstream file("D://users.txt");

    if (file.is_open())
    {
        while (!file.eof())
        {
            User user;
            file >> user.userid;
            file.ignore();
            getline(file, user.username, ',');
            getline(file, user.password, ',');
            getline(file, user.user_type, '\n');

            if (!user.username.empty())
            {
                users->push_back(user);
            }
        }
        file.close();
    } else
    {
        cout << "Khong the mo tap tin de doc thong tin nguoi dung." << endl;
    }
}

void SuaSach() {
    string isbn;
    cout << "Nhap ISBN sach can sua: ";
    cin >> isbn;
    Book s ;
    for (Book& s : *books) {
        if (s.isbn == isbn) {
            cout << "Nhap thong tin moi cho sach:" << endl;
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, s.title);
    cout << "Chu de : ";
    getline(cin, s.subject);
    cout << "Tac gia : ";
    getline(cin, s.author);
    cout << "Nha xuat ban : ";
    getline(cin, s.publisher);
cout << "Ngay xuat ban : ";
    getline(cin, s.date);
    cout << "So trang : ";
    cin >> s.pages;
    cout << "So ban  copy: ";
    cin >> s.copies;
            cout << "Thong tin sach da duoc cap nhat lai." << endl;
            return;
        }
    }

    cout << "Khong tim thay sach ISBN '" << isbn << "'." << endl;
}

void XoaSach()
{
    string isbn;
    Book s ;
cout << "Nhap  ISBN cua sach can xoa : ";
    cin >> isbn;

  auto it = find_if(books->begin() , books->end(), [isbn](const Book& s)
  {
    return s.isbn == isbn;
  });
  if ( it != books-> end())
  {
    books-> erase(it);
  }
  cout << " sach " << isbn <<" da duoc xoa "<< endl;
  return ;
    cout << "Khong co sach do dau cin trai ISBN '" << isbn << "'." << endl;
}
void xoa_nguoidung()
{
    string username;
    User u ;
    cout << "Nhap ten nguoi dung can xoa : ";
    cin >> username;

  auto it = find_if(users->begin() , users->end(), [username](const User& u)
  {
    return u.username == username;
  });
  if ( it != users-> end())
  {
    users-> erase(it);
  }
  cout << " Ten nguoi dung " << username <<" da duoc xoa "<< endl;
  return ;
    cout << "Khong co khong co ten nguoi dung" << username << "'." << endl;
}
int main()
{
    doc_tt_sach();
    doc_tt_nguoi_dung();
    int chon_tai_khoan;
  
    User tai_khoan;
    lap: 
    cout << " Chon loai tai khoan " << endl ;
        cout << " 1.Tai khoan user "<< endl;
        cout << " 2.Tai khoan cap cao" << endl ;
        cout << " 0. Ket thuc. " << endl;
        cout << "Lua chon loai tai khoan: ";
        cin >> chon_tai_khoan ;
        if ( chon_tai_khoan == 1 )
            {
                Dang_Nhapuser();
                goto lap ; 
            }
        else if (chon_tai_khoan == 0)
        {
            cout << "Chuong trinh da ket thuc!" << endl;
            return 0;
        }
         else if ( chon_tai_khoan  == 2 )
        {
            Dang_Nhap();
            int edit ;
            if (tai_khoan.userid != -1 )
            {
                cout << "Dang nhap thanh cong " << tai_khoan.username << "!" << endl;
                do
                {
                    cout << " 1. Them sach . "<< endl;
                    cout << " 2. Sua sach . " << endl;
                    cout << " 3. Xoa sach ."<< endl;
                    cout << " 4. Them nguoi dung." << endl;
                    cout << " 5. Sua ten nguoi dung." << endl;
                    cout << " 6. Xoa nguoi dung. " << endl;
                    cout << " 0. De ket thuc ." << endl;
                    cout << " 7. Quay lai ." << endl; 
                    cout << "   Nhap lua chon : ";
                    cin >> edit ;
                    switch (edit )
                    {
                        case 1 : 
                            Them_sach();
                            luu_tt_sach();
                            break;
                        case 2 :
                            SuaSach();
                            luu_tt_sach();
                            break;
                        case 3 : 
                            XoaSach();
                            luu_tt_sach();
                            break;
                        case 4 : 
                            tao_tk();
                            luu_tt_nguoi_dung();
                            break;
                        case 5  : 
                            suaten_nguoidung();
                            luu_tt_nguoi_dung();
                            break;
                        case 6 : 
                            xoa_nguoidung();
                            luu_tt_nguoi_dung();
                            break;
                        case 7 : 
                            goto lap; 
                            break;
                        case 0 :
                            cout  << " Chuong trinh da ket thuc : " << endl ; 
                            break;
                        default :
                            cout << " Lua chon khong hop le : " << endl ;
                            break;
                    }
                } while( edit != 0 );
            } 
        } 
        else {
        cout << " Lua chon khong hop le "    << endl ; 
        cout << " Vui long nhap lai lua chon : " << endl ; 
        goto lap; 
        }
    delete books;
    delete users;

    return 0;
}
