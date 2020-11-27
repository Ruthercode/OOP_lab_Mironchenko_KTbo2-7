#include "Interactor.h"

Interactor::Interactor(): _container(nullptr)
{
}

Interactor::~Interactor()
{
    if (_container != nullptr)
    {
        delete _container;
    }
}

void Interactor::_Help() const
{
    std::cout <<"===========================================\n";
    std::cout << "Commands: \n";
    std::cout << "1) Add new item\n";
    std::cout << "2) Search by name\n";
    std::cout << "3) Search by rating\n";
    std::cout << "4) Search by job place\n";
    std::cout << "5) Search by birth date\n";
    std::cout << "6) Get a list of all candidates\n";
    std::cout << "7) Change container type\n";
    std::cout << "8) Remove item by id\n";
    std::cout << "9) Find item by id\n";
    std::cout << "10) Update candidate name by id\n";
    std::cout << "11) Update candidate rating by id\n";
    std::cout << "12) Update candidate job place by id\n";
    std::cout << "13) Update candidate birth date by id\n";
    std::cout << "14) Help\n";
    std::cout << "0) Exit\n";
    std::cout <<"===========================================\n";
}

void Interactor::_Interaction(const std::string& file_to_input) 
{
    int command = -1;

    while (command != 0)
    {
        std::cout <<"Please, enter your command: ";
        std::cin >> command;

        std::vector<Candidate*> result;
        if (command == 0)
        {
            continue;
        }
        else if (command == 1)
        {
            try 
            {
                _container->AddItem(_ReadCandidate(std::cin, true));
            }
            catch (std::logic_error e)
            {
                std::cout << "There is so mistakes in data: " << e.what() << '\n';
            }
        }
        else if (command == 2)
        {
            std::cout << "Please, enter full name: ";
            std::string firstName;
            std::string secondName;
            std::string lastName;
            std::cin >> firstName >> secondName >> lastName;
            std::string fullName = firstName + " " + secondName + " " + lastName;


            result = _container->SearchByName(fullName);
        }
        else if (command == 3)
        {
            std::cout << "Please, enter a rating: ";

            double rait;
            std::cin >> rait;

            std::cout << "Please, enter a type of seatching(L- less, M - more, E - equal): ";
            char type;
            std::cin >> type;

            try
            {
                result = _container->SearchByRating(rait, type);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
            }
            
        }
        else if (command == 4)
        {
            std::cout << "Please, enter a place of job: ";
            std::string job;
            std::cin >> job;


            result = _container->SearchByJobPlace(job);
        }
        else if (command == 5)
        {
            std::cout << "Please, enter a date (dd.mm.yy): ";

            int d, m, y;

            std::cin >> d;
            std::cin.get();
            std::cin >> m;
            std::cin.get();
            std::cin >> y;
            
            Date date(d,m,y);

            std::cout << "Please, enter a type of seatching(L- less, M - more, E - equal): ";
            char type;
            std::cin >> type;


            try
            {
                result = _container->SearchByBirthDate(date, type);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
            }
        }
        else if (command == 6)
        {
            result = _container->GetCandidates();
        }
        else if (command == 7)
        {

            delete _container;
            _ChooseContainer();
            _FileParse(file_to_input);
        }
        else if (command == 8)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;


            _container->RemoveById(id);
        }
        else if (command == 9)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;

            Candidate* candidate = _container->FindById(id);

            if (candidate == nullptr) std::cout << "Candiate with given id does not exist\n";
            else std::cout << *candidate;
        }
        else if (command == 10)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;

            std::cout << "Please, enter new full name: ";
            std::string firstName;
            std::string secondName;
            std::string lastName;
            std::cin >> firstName >> secondName >> lastName;
            std::string fullName = firstName + " " + secondName + " " + lastName;

            _container->UpdateNameById(id, fullName);
        }
        else if (command == 11)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;

            std::cout << "Please, enter a new rating: ";

            double rait;
            std::cin >> rait;

            _container->UpdateRatingById(id, rait);
        }
        else if (command == 12)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;

            std::cout << "Please, enter a new place of job: ";
            std::string job;
            std::cin >> job;

            _container->UpdateJobPlaceById(id, job);
        }
        else if (command == 13)
        {
            std::cout << "Please, enter id: ";
            int id;
            std::cin >> id;

            std::cout << "Please, enter a date (dd.mm.yy): ";

            int d, m, y;

            std::cin >> d;
            std::cin.get();
            std::cin >> m;
            std::cin.get();
            std::cin >> y;
            try
            {
                Date date(d,m,y);
                _container->UpdateBirthDatById(id,date);
            }
            catch(std::logic_error e)
            {
                std::cout << e.what() << '\n';
            }
            
            
        }
        else if (command == 14)
        {
            _Help();
        }

        for (auto c : result)
        {
            std::cout << *c << std::endl;
        }
        
    }
    
}

Candidate Interactor::_ReadCandidate(std::istream& in, bool greaters) const
{
    std::ios::sync_with_stdio(0);
    if (greaters) std::cout << "Please, enter full name: ";

    std::string firstName;
    std::string secondName;
    std::string lastName;
    in >> firstName >> secondName >> lastName;
    std::string fullName = firstName + " " + secondName + " " + lastName;

    if (greaters) std::cout << "Please, enter a date (dd.mm.yy): ";

    int d, m, y;

    in >> d;
    in.get();
    in >> m;
    in.get();
    in >> y;
    Date date(d,m,y);

    if (greaters) std::cout << "Please, enter a place of job: ";

    std::string job;
    in >> job;

    if (greaters) std::cout << "Please, enter a rating: ";

    double rait;
    in >> rait;

    return Candidate(fullName, date, job,rait);
}
void Interactor::_FileParse(const std::string& file_to_input)
{
    int n;
    std::ifstream fin(file_to_input);
    fin >> n;

    for (int i = 0; i < n; ++i)
    {
        try {
            _container->AddItem(_ReadCandidate(fin,false));
        }
        catch (std::logic_error e)
        {
            std::cout << "There is so mistakes in file: " << e.what() << '\n';
            exit(1);
        }
    }

    fin.close();
}

void Interactor::_ChooseContainer()
{
    std::cout << "Choose to type of a container [V: Vector, M: Map]: ";
    char type;
    std::cin >> type;

    ContainerFactory factory;
    _container = factory.GetContainer(toupper(type));

    while (_container == nullptr)
    {
        std::cout << "The given type doesn't exist. Choose from V and M [V: Vector, M: Map]: ";
        std::cin >> type;

        _container = factory.GetContainer(toupper(type));
    }
    std::cout << "You choose " << (toupper(type) == 'V' ? "vector\n" : "map\n");
}

void Interactor::Init(const std::string& file_to_input)
{
    _ChooseContainer();
    _FileParse(file_to_input);
    std::cout << "Files parsed from " << file_to_input << '\n';
    
    _Help();
    _Interaction(file_to_input);

}

