struct question
{
    int que_id;
    char que_text[160];
    char que_ch1[50];
    char que_ch2[50];
    char que_ch3[50];
    char que_ch4[50];
    int que_ans;
};
typedef struct question question;

struct test
{
    int test_id;
    char test_desc[50];
    int id_que1;
    int id_que2;
    int id_que3;
    int id_que4;
    int id_que5;
};
typedef struct test test;

struct user
{
    int user_id;
    char name[30];
    char email[20];
    char password[20];
    
};
typedef struct user user;

struct master
{
    char email[20];
    char name[30];
    int a_testid;
    int total;
    
};
typedef struct master master;