#include <stdio.h>
#include <iostream>

#include "/usr/sap/hdbclient/sdk/odbc/incl/sql.h"

int main()
{
    printf("hello world\n");
    std::cout<<"test is test"<<std::endl;

    SQLHENV env;
    SQLHDBC dbc;
    SQLRETURN ret;
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;
    
    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);

    return 0;
}