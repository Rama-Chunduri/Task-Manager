
using namespace std;

class User{
    private: 
        string userName;
        string password;
    
    public:

        User::User();
        User::User(string _userName, string _password);
	
	    void SetUserName (string _userName);
	    void SetPassword (string _password);

	    string GetUserName();
	    string GetPassword();

        void loadtasks();


};