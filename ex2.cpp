
struct BookCollection
{
    Book Booklist[1000];
};

class Book
{
    string title;
    string author;
    string hello;
    bool availability;
};

class LoanRecord
{
    private:
    unsigned int num_books = 1000;
    Book LoanedBooklist[num_books];

    public:
    void borrowRequest(Book book);
    bool check_availability(Book book); // LoanRecord should be responsible 
                                        // for checking book availability

};

void LoanRecord::borrowRequest(Book book)
{
    if(check_availability(book))
    {
        // details of book transaction goes here
    }
}

bool LoanRecord::check_availability(Book book)
{
    for(int i = 0; i < num_books; i++)
    {
        if(LoanedBooklist[i] == book)
            return false;
    }

    return true;
}

class User
{
    private:
    Book loanedBook = NULL;

    public:
    void loanRequest();
};



class Library
{
    private:
    struct BookCollection Collection;
    LoanRecord Loan_Record; //Library is responsible for creating LoanRecord

    public:
    void borrowRequest(Book book); // Library is responsible for user borrowing request
                                   // according to Creator Pattern; however, 
                                   // we can delegate responsibility to LoanRecord
                                   // as per Low Coupling/High Cohesion Pattern

};


void Library::borrowRequest(Book book)
{
    Loan_Record.borrowRequest(book);
}
