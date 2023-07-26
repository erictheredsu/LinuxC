//hana odbc test

#include <iostream>
#include <string>
#include "/usr/sap/hdbclient/sdk/odbc/incl/sql.h"
#include "/usr/sap/hdbclient/sdk/odbc/incl/sqlext.h"
#include <unistd.h> 


using namespace std;

void extract_error(
    string fn,
    SQLHANDLE handle,
    SQLSMALLINT type)
{
    SQLINTEGER   i = 0;
    SQLINTEGER   native;
    SQLCHAR      state[ 7 ];
    SQLCHAR      text[1024];
    SQLSMALLINT  len;
    SQLRETURN    ret;

    cout << "\nThe driver reported the following diagnostics whilst running " << fn << "\n\n";

    do
    {
        ret = SQLGetDiagRec(type, handle, ++i, state, &native, text,
                            sizeof(text), &len );
        if (SQL_SUCCEEDED(ret))
            printf("%s:%ld:%ld:%s\n", state, i, native, text);
    }
    while( ret == SQL_SUCCESS );
}



int main()
{
    cout << "Program had started.." << endl;

    SQLHENV env;
    SQLHDBC dbc;
    SQLRETURN ret;
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;

    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);

    cout << "Attempting Connection " << endl;
    //SQLCHAR hanaConnString [] = "driver={HDBODBC};SERVERNODE=CNPVGVB1TOT10:30013;DATABASENAME=DEV;DATABASE=SLDDATA;UID=SYSTEM;PWD=Initial0;packetSize=209715";
    SQLCHAR hanaConnString [] = "DRIVER={HDBODBC};SERVERNODE=CNPVG50844898.b1cloud.smes.sap.corp:30013;DATABASENAME=DEV;DATABASE=SLDDATA;UID=NONSYSTEM;PWD=Initial0;encrypt=true;sslHostNameInCertificate=CNPVG50844898.b1cloud.smes.sap.corp";
    ret = SQLDriverConnect(dbc, NULL, hanaConnString, SQL_NTS,
                         outstr, sizeof(outstr), &outstrlen,
                         SQL_DRIVER_NOPROMPT);

    cout << "Connecting ... " << endl;
    if(ret!=0)
    {
        extract_error("SQLDriverConnect", dbc, SQL_HANDLE_DBC);
    }

     SQLHANDLE stmt; /* statement handle */
     ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    SQLCHAR selectStmt[] = "select top 1000 * from objects";
    SQLExecDirect(stmt, selectStmt, SQL_NTS);
    ret = SQLFetch(stmt);
    // while(ret == SQL_SUCCESS) {
    //   ret = SQLFetch(stmt);
    // }

    if (ret!= SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO)
    {
        cout << "fail to connect" << endl;

    }
    
    if(ret == SQL_SUCCESS)
    {
        cout << "connected" << endl;
    }

    sleep(180);

    return 0;
}