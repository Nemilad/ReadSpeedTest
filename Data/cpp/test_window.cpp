#include "test_window.h"
#include "ui_test_window.h"

test_window::test_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test_window)
{
    ui->setupUi(this);
}

test_window::~test_window()
{
    delete ui;
    ans.clear();
    qst.clear();
    user_ans.clear();
    ans_var.clear();
}

void test_window::closeEvent(QCloseEvent *e)
{
    if(testended==false) emit(result(0));
    testended=true;
    e->accept();
}

test_window *test_window::get_test_window()
{
    return this;
}

void test_window::update_qst()
{
    QString temp=ans[curr_qst_num-1];
    for(int i=0;i<4;i++)curr_ans[i]=temp.split("/").at(i);
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(&curr_ans[0],&curr_ans[4]);
    ui->radioButton_1->setText(curr_ans[0]);
    ui->radioButton_2->setText(curr_ans[1]);
    ui->radioButton_3->setText(curr_ans[2]);
    ui->radioButton_4->setText(curr_ans[3]);
    ui->label->setText(qst[curr_qst_num-1]);
}

void test_window::recieveData(QStringList test_q, QStringList test_a)
{
    qst=test_q;
    ans=test_a;
    for(int i=0;i<ans.size();i++)
    {
        QString temp=ans[i];
        ans_var+=temp.split("/").at(0);
    }
}

void test_window::startTest()
{
    testended=false;
    butt_num.addButton(ui->radioButton_1,1);
    butt_num.addButton(ui->radioButton_2,2);
    butt_num.addButton(ui->radioButton_3,3);
    butt_num.addButton(ui->radioButton_4,4);

    curr_qst_num=1;
    update_qst();
}

void test_window::on_pushButton_next_pressed()
{
    if(butt_num.checkedButton()!=0 && testended==false)
    {
        if(curr_qst_num==qst.size())
        {
            user_ans+=butt_num.checkedButton()->text();
            int temp=0;
            for(int i=0;i<user_ans.size();i++)
            {
                if(user_ans[i]==ans_var[i])temp++;
            }
            testended=true;
            emit(result((float)temp/user_ans.size()));
        }
        else
        {
            if(curr_qst_num==qst.size()-1)
            {
                ui->pushButton_next->setText("Завершить");
                user_ans+=butt_num.checkedButton()->text();
                curr_qst_num++;
                update_qst();
                butt_num.setExclusive(false);
                butt_num.checkedButton()->setChecked(false);
                butt_num.setExclusive(true);
            }
            else
            {
                user_ans+=butt_num.checkedButton()->text();
                curr_qst_num++;
                update_qst();
                butt_num.setExclusive(false);
                butt_num.checkedButton()->setChecked(false);
                butt_num.setExclusive(true);

            }
        }
        if(curr_qst_num>1)ui->pushButton_prev->setEnabled(true);
    }
}

void test_window::on_pushButton_prev_pressed()
{
    if(curr_qst_num-1==qst.size())ui->pushButton_next->setText("Далее");
    curr_qst_num--;
    user_ans.removeLast();
    update_qst();
    if (butt_num.checkedButton()!=0)
    {
        butt_num.setExclusive(false);
        butt_num.checkedButton()->setChecked(false);
        butt_num.setExclusive(true);
    }
    if(curr_qst_num==1)ui->pushButton_prev->setEnabled(false);
}
