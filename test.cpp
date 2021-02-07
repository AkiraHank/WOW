//
// Created by Hank on 2021/2/7.
//
class ICommand{public : virtual void vfunc(){}};
class CSession : public ICommand{};

void Test(ICommand *  pCommand){delete pCommand;pCommand = NULL;}

int main(int argc, char *argv[])
{
     CSession* sessions = new CSession();

    Test(sessions);

    return 0;
}
