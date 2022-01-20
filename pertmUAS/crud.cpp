#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

int pilih;
char kembali;

class config
{

private:
    const char *hostname = "172.19.128.1";
    //const char* hostname = "127.0.0.1";
    const char *user = "root";
    const char *pass = "";
    const char *dbname = "uas_yohanes_bagas_pbo";
    unsigned int port = 3306;
    const char *unixsocket = NULL; 
    unsigned long clientflag = 0;
    string current_db;       
    

public:
    MYSQL *connectdb()
    {
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn)
        {
            cout << "berhasil" << endl;
            return conn;
        }
        else
        {
            cout << "gagal" << endl;
            return conn;
        }
    }


    void displayData(MYSQL *conn)
    {

        MYSQL_ROW row;
        MYSQL_RES *result;

        if (conn)
        {
            int qstate = mysql_query(conn, "SELECT * FROM mahasiswa JOIN dosen; ");
            if (!qstate)
            {
                result = mysql_store_result(conn);
                int count = mysql_num_fields(result);
                cout << "\t\t\t\t---( DATA MAHASISWA )---\t\t\t\t\t\t\t---( DATA DOSEN )---\n";
                cout << "\tID\tNIM\tNAMA MAHASISWA\tDibuat pada\t\tTerakhir update\t\tID\tKODE\tNAMA DOSEN\t\tDibuat pada\tTerakhir update\n";
                //cout <<"\tID\tNIM\tNAMA\t\tDIBUAT TANGGAL\t\tTERAKHIR UPDATE\n";
                while (row = mysql_fetch_row(result))
                {

                    for (int i = 0; i < count; i++)
                    {
                        cout << "\t" << row[i];
                        if (i == 2 || i == 7)
                        {
                            cout << "\t";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Data Kosong" << endl;
        }
    }

    int countMhsDosen(MYSQL *conn)
    {
        int status = 0;
        MYSQL_ROW row;
        MYSQL_RES *result;

        if (conn)
        {
            int qstate = mysql_query(conn, "SELECT * FROM mahasiswa JOIN dosen; ");
            if (!qstate)
            {
                result = mysql_store_result(conn);
                int count = mysql_num_fields(result);

                //cout <<"\tID\tNIM\tNAMA\t\tDIBUAT TANGGAL\t\tTERAKHIR UPDATE\n";
                while (row = mysql_fetch_row(result))
                {
                    status += 1;
                }
            }
        }

        return status;
    }
    
};

class dosen : public config
{
public:
    void displayData(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;

        if (conn)
        {
            int qstate = mysql_query(conn, "SELECT * FROM dosen; ");
            if (!qstate)
            {
                result = mysql_store_result(conn);
                int count = mysql_num_fields(result);
                cout << "\t\t\t\t---( DATA DOSEN )---\n";
                cout << "\tID\tKODE\tNAMA DOSEN\t\tDibuat pada\t\tTerakhir update\n";
                //cout <<"\tID\tNIM\tNAMA\t\tDIBUAT TANGGAL\t\tTERAKHIR UPDATE\n";
                while (row = mysql_fetch_row(result))
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\t" << row[i];
                        if (i == 2 || i == 7)
                        {
                            cout << "\t";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Data Kosong" << endl;
        }
    }

    void InsertDataDosen(MYSQL *conn)
    {
        int qstate = 0;
        stringstream inserttodb;
        string nim, nama, id;
        // cout << "insert ID : "<<endl;
        // cin>>id;
        cout << "insert Kode Dosen : " << endl;
        cin >> nim;
        cout << "insert Nama : " << endl;
        cin >> nama;
        inserttodb << "INSERT INTO dosen (kd_dosen, nama) VALUES ('" + nim + "','" + nama + "')";
        string query = inserttodb.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "berhasil insert" << endl;
        }
        else
        {
            cout << "gagal" << endl;
        }
    }

    void updateDataDosen(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;
        string id;
        cout << "masukan kode dosen : " << endl;
        cin >> id;
        stringstream selectdb, updatedb;
        selectdb << "SELECT * FROM dosen WHERE kd_dosen = '" + id + "' ";
        string query = selectdb.str();
        const char *q = query.c_str();
        mysql_query(conn, q);
        result = mysql_store_result(conn);
        int count = mysql_num_fields(result);
        my_ulonglong x = mysql_num_rows(result);
        string nim, nama;
        if (x > 0)
        {
            cout << "insert kode dosen : " << endl;
            cin >> nim;
            cout << "insert Nama  dosen: " << endl;
            cin >> nama;
            updatedb << "UPDATE dosen SET kd_dosen = '" + nim + "', nama= '" + nama + "' WHERE kd_dosen = '" + id + "' ";
            string query = updatedb.str();
            const char *q = query.c_str();
            mysql_query(conn, q);
        }
        else
        {
            cout << "error\n";
        }
    }

    void deleteDataDosen(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;
        string id;
        cout << "Masukan kode dosen: " << endl;
        cin >> id;
        stringstream selectdb, deletedb;
        selectdb << "SELECT * FROM dosen WHERE kd_dosen = '" + id + "' ";
        string query = selectdb.str();
        const char *q = query.c_str();
        mysql_query(conn, q);
        result = mysql_store_result(conn);
        int count = mysql_num_fields(result);
        my_ulonglong x = mysql_num_rows(result);

        if (x > 0)
        {
            deletedb << "DELETE FROM dosen WHERE kd_dosen = '" + id + "' ";
            string query = deletedb.str();
            const char *q = query.c_str();
            mysql_query(conn, q);
        }
        else
        {
            cout << "error\n";
        }
    }
};

class mahasiswa : public config
{
public:
    

    void InsertDataMahasiswa(MYSQL *conn)
    {
        int qstate = 0;
        stringstream inserttodb;
        string nim, nama, id;
        // cout << "insert ID : "<<endl;
        // cin>>id;
        cout << "insert NIM : " << endl;
        cin >> nim;
        cout << "insert Nama : " << endl;
        cin >> nama;
        inserttodb << "INSERT INTO mahasiswa (nim, nama) VALUES ('" + nim + "','" + nama + "')";
        string query = inserttodb.str();
        const char *q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << "berhasil insert" << endl;
        }
        else
        {
            cout << "gagal" << endl;
        }
    }

    void displayData(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;

        if (conn)
        {
            int qstate = mysql_query(conn, "SELECT * FROM mahasiswa; ");
            if (!qstate)
            {
                result = mysql_store_result(conn);
                int count = mysql_num_fields(result);
                cout << "\t\t\t\t---( DATA MAHASISWA )---\n";
                cout << "\tID\tNIM\tNAMA MAHASISWA\tDibuat pada\t\tTerakhir update\n";
                //cout <<"\tID\tNIM\tNAMA\t\tDIBUAT TANGGAL\t\tTERAKHIR UPDATE\n";
                while (row = mysql_fetch_row(result))
                {
                    for (int i = 0; i < count; i++)
                    {
                        cout << "\t" << row[i];
                        if (i == 2 || i == 7)
                        {
                            cout << "\t";
                        }
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Data Kosong" << endl;
        }
    }

    void updateDataMahasiswa(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;
        string id;
        cout << "enter nim : " << endl;
        cin >> id;
        stringstream selectdb, updatedb;
        selectdb << "SELECT * FROM mahasiswa WHERE nim = '" + id + "' ";
        string query = selectdb.str();
        const char *q = query.c_str();
        mysql_query(conn, q);
        result = mysql_store_result(conn);
        int count = mysql_num_fields(result);
        my_ulonglong x = mysql_num_rows(result);
        string nim, nama;
        if (x > 0)
        {
            cout << "insert NIM : " << endl;
            cin >> nim;
            cout << "insert Nama : " << endl;
            cin >> nama;
            updatedb << "UPDATE mahasiswa SET nim = '" + nim + "', nama= '" + nama + "' WHERE nim = '" + id + "' ";
            string query = updatedb.str();
            const char *q = query.c_str();
            mysql_query(conn, q);
        }
        else
        {
            cout << "error\n";
        }
    }

    void deleteDataMahasiswa(MYSQL *conn)
    {
        MYSQL_ROW row;
        MYSQL_RES *result;
        string id;
        cout << "enter nim: " << endl;
        cin >> id;
        stringstream selectdb, deletedb;
        selectdb << "SELECT * FROM mahasiswa WHERE nim = '" + id + "' ";
        string query = selectdb.str();
        const char *q = query.c_str();
        mysql_query(conn, q);
        result = mysql_store_result(conn);
        int count = mysql_num_fields(result);
        my_ulonglong x = mysql_num_rows(result);

        if (x > 0)
        {
            deletedb << "DELETE FROM mahasiswa WHERE nim = '" + id + "' ";
            string query = deletedb.str();
            const char *q = query.c_str();
            mysql_query(conn, q);
        }
        else
        {
            cout << "error\n";
        }
    }
};

int main()
{
    config cf;
    mahasiswa mhs;
    dosen ds;
    MYSQL *conn = cf.connectdb();
    do
    {
        cout << "MENU";
        cout << "\n 0. Exit";
        cout << "\n 1. Create data mahasiswa";
        cout << "\n 2. Create data dosen";
        cout << "\n 3. Read Data Mahasiswa dan Dosen";
        cout << "\n 4. Update Data Mahasiswa";
        cout << "\n 5. Update Data Dosen";
        cout << "\n 6. Delete Data Mahasiswa ";
        cout << "\n 7. Delete Data Dosen";

        cout << "\nPilih : ";
        //cin.ignore();
        cin >> pilih;

        switch (pilih)
        {
        case 0:
            cout << "\nThanks" << endl;
            return 0;
        case 1:
            mhs.InsertDataMahasiswa(conn);
            cin.ignore();
            //ds.InsertDataDosen(conn);
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                mhs.displayData(conn);
                ////cin.ignore();
            }
            else
            {
                cf.displayData(conn);
                //cin.ignore();
            }
            break;
        case 2:
            ds.InsertDataDosen(conn);
            cin.ignore();
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                ds.displayData(conn);
                //cin.ignore();
            }
            else
            {
                cf.displayData(conn);
                //cin.ignore();
            }
            cin.ignore();
            break;
        case 3:
            cf.displayData(conn);
            // mhs.displayData(conn);
            break;
        case 4:
            mhs.updateDataMahasiswa(conn);
            cin.ignore();
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                mhs.displayData(conn);
                //cin.ignore();
            }
            else
            {
                cf.displayData(conn);
                //cin.ignore();
            }
            //mhs.displayData(conn);
            break;
        case 5:
            ds.updateDataDosen(conn);
            cin.ignore();
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                ds.displayData(conn);
                //cin.ignore();
            }
            else
            {
                cf.displayData(conn);
            }
            //ds.InsertDataDosen(conn);
                
            //cf.displayData(conn);
            break;
        case 6:
            mhs.deleteDataMahasiswa(conn);
            cin.ignore();
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                mhs.displayData(conn);
                //cin.ignore();
            }
            else
            {
                cf.displayData(conn);
                //cin.ignore();
            }
            break;
            //ds.InsertDataDosen(conn);
            //cf.displayData(conn);
            break;
        case 7:
            ds.deleteDataDosen(conn);
            cin.ignore();
            if (cf.countMhsDosen(conn) == 0)
            {
                cout << "Salah satu data dari mahasiswa dan dosen belum ada" << endl;
                ds.displayData(conn);
                //cin.ignore();
            }
            else
            {
                cf.displayData(conn);
                //cin.ignore();
            }
            break;
            //ds.InsertDataDosen(conn);
            //cf.displayData(conn);
            break;
        default:
            cout << "Pilihan Salah" << endl;
            break;
        }
        cin.ignore();
        cout << "Ingin memilih menu lain (y/t)? ";
        cin >> kembali;
        //cout << endl;
        cin.ignore();
    } while (kembali != 't');
    cout << "Thanks" << endl;

    return 0;
}