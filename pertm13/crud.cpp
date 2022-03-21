#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

int pilih;
char kembali;
const char* hostname = "172.29.176.1";
//const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "";
const char* dbname = "pertemuan_13";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;
string current_db;

MYSQL* connectdb(){
    MYSQL * conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
    if (conn) {
        cout<< "berhasil"<<endl;
        return conn;
    } else {
        cout<< "gagal"<<endl;
        return conn;
    }
}

void dataBaseAndTableValidation (MYSQL*conn, string whichCase, string keyword){
    stringstream dbValidation, tableValidation;
    string query = "";
    MYSQL_ROW row;
    MYSQL_RES* result;
    if(whichCase=="db"){
        dbValidation
        <<"SELECT COUNT(*) FROM information_schema.tables"
        <<" WHERE table_schema LIKE '%"+keyword+"%';";
        query = dbValidation.str();
        //cout<<query<<endl;
        const char* q = query.c_str();
        int qstate = mysql_query(conn,q);
        if(!qstate){
            result = mysql_store_result(conn);
            int count = mysql_num_fields(result);
            string dataCatch="";
            while(row = mysql_fetch_row(result)){
                for(int i=0; i<count;i++){
                    dataCatch= row[i];
                }
                cout<<endl;
            }
            cout<< dataCatch<<" Database ";
            cout <<"ditemukan !"<<endl;

        }
        else {
            cout<<"Database belum ada!"<<endl;
        }
    }
}

void createDatabase(MYSQL* conn){
    string db;
    stringstream createdb, dropdb, createulangdb;
    cout<<"input nama databasenya: \n";
    cin >> db;
    createdb << "CREATE DATABASE "+db+" ";
    string query = createdb.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn, q);
    if(qstate==0){
        cout<<"berhasil create db\n";
    }else if (qstate ==0)
    {
        dropdb << "DROP DATABASE IF EXISTS "+db+" ";
        string query = dropdb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"berhasil drop\n";
    }else{
        createulangdb << "CREATE DATABASE "+db+" ";
        string query = createulangdb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"create ulang database\n";
    }
    
}

void createTable(MYSQL* conn){
    string db;
    stringstream createtb, droptb, createulangtb;
    cout<<"input nama databasenya: \n";
    cin >> db;
    createtb << "CREATE TABLE"+db+" ";
    string query = createtb.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn, q);
    if(qstate==0){
        cout<<"berhasil create db\n";
    }else if (qstate ==0)
    {
        droptb << "DROP DATABASE IF EXISTS "+db+" ";
        string query = droptb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"berhasil drop\n";
    }else{
        createulangtb << "CREATE DATABASE "+db+" ";
        string query = createulangtb.str();
        const char* q = query.c_str();
        int qstate = mysql_query(conn, q);
        cout<<"create ulang database\n";
    }
    
}

void insertData(MYSQL* conn){
    int qstate =0;
    stringstream inserttodb;
    string nim, nama, id;
    cout << "insert ID : "<<endl;
    cin>>id;
    cout << "insert NIM : "<<endl;
    cin>>nim;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO mahasiswa (id, nim, nama) VALUES ('"+id+"','"+nim+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;

    }
}


void displayData(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* result;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM mahasiswa");
        if(!qstate){
            result = mysql_store_result(conn);
            int count = mysql_num_fields(result);
            cout << "==============LIST DATA==============\n";
            cout <<"\tID\tNIM\tNAMA\n";
            while(row = mysql_fetch_row(result)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}

void updateData(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* result;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM mahasiswa WHERE nim = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    result = mysql_store_result(conn);
    int count = mysql_num_fields(result);
    my_ulonglong x = mysql_num_rows(result);
    string nim, nama;
    if(x>0){
        cout << "insert NIM : "<<endl;
        cin>>nim;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE mahasiswa SET nim = '"+nim+"', nama= '"+nama+"' WHERE nim = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}



void deleteData(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* result;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    result = mysql_store_result(conn);
    int count = mysql_num_fields(result);
    my_ulonglong x = mysql_num_rows(result);

    if(x>0){
        deletedb <<"DELETE FROM mahasiswa WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

int main(){
    MYSQL* conn = connectdb();
    dataBaseAndTableValidation(conn,"db","arjuna");
    do{
        cout<<"MENU";
        cout<<"\n 0. Exit";
        cout<<"\n 1. Create ";
        cout<<"\n 2. Read ";
        cout<<"\n 3. Update ";
        cout<<"\n 4. Delete ";
        cout<<"\n 5. Create Database ";
        
        cout<<"\nPilih : "; cin>>pilih;

        switch(pilih){
            case 0:
                cout<<"\nThanks"<<endl;
                return 0;
            case 1:
				insertData(conn);
                displayData(conn);
                break;
            case 2:
				displayData(conn);
                break;
            case 3:
                updateData(conn);
                displayData(conn);
                break;
            case 4:
                deleteData(conn);
                displayData(conn);
                break;
            case 5:
                createDatabase(conn);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
                break;
            }
            cout<<"Ingin memilih menu lain (y/t)? ";
            cin>>kembali;
            cout<<endl;
        }
        while (kembali!= 't');
        cout<<"Thanks"<<endl;
    return 0;

}