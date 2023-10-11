#include "usermodel.hpp"
#include "db.h"
bool UserModel::insert(User &user){
    //组装sql语句
    char sql[1024]  = {0};
    sprintf(sql,"insert into user(name,password,state) values('%s','%s','%s')",
            user.getName().c_str(),user.getPwd().c_str(),user.getState().c_str());
    
    MySQL mysql;
    if (mysql.connect())
    {
        if(mysql.update(sql)){
            //插入成功用户生成主键id;
            user.setID(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}