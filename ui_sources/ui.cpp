#include "../ui_headers/ui.hpp"
#include "../ui_headers/io_functions.hpp"

using namespace std;

template <typename T>
void print_sequence(sequence<T> *container)
{
    cout << "[";
    for (int i = 0; i != container->get_length(); ++i)
    {
        if (i != 0)
        {
            cout << ", ";
        }
        cout << container->get(i);
    }
    cout << "]" << endl;
}

template <typename T>
void print_stack(stack<T> *container)
{
    stack<T> *new_stack = new stack<T>(*container);
    for (int i = 0; i != container->size(); ++i)
    {
        if (i == container->size() - 1)
        {
            cout << "| " << "data = " << new_stack->top() << " |" << endl;
            break;
        }
        cout << "| " << "data = " << new_stack->top() << " |->";
        new_stack->pop();
    }
    delete new_stack;
}

void check_input(int &choice)
{
    if (!(cin >> choice))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input: programm cann't read letters");
    }
}

void output_types_menu(int &sequence_type)
{
    int type_choice;
    while (true)
    {
        cout << "Choose data type: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Double" << endl;
        cout << "3. String" << endl;
        cout << "4. Complex" << endl;
        cout << "5. Student" << endl;
        cout << "6. Professor" << endl;
        cout << "7. Return to Main Menu" << endl;
        cout << "0. Exit " << endl;
        try
        {
            check_input(type_choice);
            switch (type_choice)
            {
            case 1:
                set_sequence_type<int>(sequence_type);
                break;
            case 2:
                set_sequence_type<double>(sequence_type);
                break;
            case 3:
                set_sequence_type<string>(sequence_type);
                break;
            case 4:
                set_sequence_type<complex>(sequence_type);
                break;
            case 5:
                set_sequence_type<student>(sequence_type);
                break;
            case 6:
                set_sequence_type<professor>(sequence_type);
                break;
            case 7:
                break;
            case 0:
                exit(0);
            default:
                throw invalid_argument("Invalid choice");
                cout << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            continue;
        }
    }
}

template <typename T>
void set_sequence_type(int &sequence_type)
{
    sequence<T> *seq = nullptr;
    if (sequence_type == 1)
    {
        seq = new array_sequence<T>();
    }
    if (sequence_type == 2)
    {
        seq = new list_sequence<T>();
    }
    if (sequence_type == 3)
    {
        delete seq;
        stack<T> *seq = new stack<T>();
        output_stack_menu(seq);
    }
    if (sequence_type == 4)
    {
        delete seq;
        stack<T> *seq = new stack<T>(new array_sequence<T>());
        output_stack_menu(seq);
    }
    if (seq)
    {
        output_sequence_menu(seq);
    }
}
template <typename T>
void output_sequence_menu(sequence<T> *seq)
{
    int choice;
    T element;
    int index;
    int count;
    sequence<T> *buffer_sequence = nullptr;
    while (true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n=== Sequence Menu ===" << endl;
        cout << "Choose option: " << endl;
        cout << "1. Get first element " << endl;
        cout << "2. Get last element " << endl;
        cout << "3. Get index element " << endl;
        cout << "4. Add element to end" << endl;
        cout << "5. Add element to beginning " << endl;
        cout << "6. Insert element to index " << endl;
        cout << "7. Concat with another " << endl;
        cout << "8. Immutable add element to end" << endl;
        cout << "9. Immutable add element to beginning " << endl;
        cout << "10. Immutable insert element to index " << endl;
        cout << "11. Immutable concat with another " << endl;
        cout << "12. Print sequence " << endl;
        cout << "13. Print all sequences " << endl;
        cout << "14. Clear sequence " << endl;
        cout << "0. Return to previous menu" << endl;

        try
        {
            check_input(choice);
            switch (choice)
            {
            case 1:
            {
                cout << "First element: " << seq->get_first() << endl;
                break;
            }
            case 2:
            {
                cout << "Last element: " << seq->get_last() << endl;
                break;
            }
            case 3:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Element: " << seq->get(index) << endl;
                break;
            }
            case 4:
            {
                cout << "Input element: ";
                cin >> element;
                seq = seq->append_element(element);
                cout << "Element added." << endl;
                break;
            }
            case 5:
            {
                cout << "Input element: ";
                cin >> element;
                seq = seq->prepend_element(element);
                cout << "Elemnt added." << endl;
                break;
            }
            case 6:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Input element: ";
                cin >> element;
                seq = seq->insert_element(element, index);
                cout << "Element added." << endl;
                break;
            }
            case 7:
            {
                cout << "Creating a new sequence to concat..." << endl;
                sequence<T> *other = new array_sequence<T>();
                cout << "Input count of elements: ";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    cout << "Element" << i << ": ";
                    cin >> element;
                    other = other->append_element(element);
                }
                seq = seq->concat(*other);
                cout << "Sequences were concatenated." << endl;
                delete other;
                break;
            }
            case 8:
            {
                cout << "Input element: " << endl;
                cin >> element;
                buffer_sequence = seq->immutable_append_element(element);
                cout << "Element added." << endl;
                break;
            }
            case 9:
            {
                cout << "Input element: " << endl;
                cin >> element;
                buffer_sequence = seq->immutable_prepend_element(element);
                cout << "Element added." << endl;
                break;
            }
            case 10:
            {
                cout << "Choose index: ";
                cin >> index;
                cout << "Input element: ";
                cin >> element;
                buffer_sequence = seq->immutable_insert_element(element, index);
                cout << "Element added." << endl;
                break;
            }
            case 11:
            {
                cout << "Creating a new sequence to concat..." << endl;
                sequence<T> *other = new array_sequence<T>();
                cout << "Input count of elements: ";
                cin >> count;
                for (int i = 0; i < count; ++i)
                {
                    cout << "Element" << i << ": ";
                    cin >> element;
                    other = other->append_element(element);
                }
                buffer_sequence = seq->immutable_concat(*other);
                cout << "Sequences were concatenated." << endl;
                delete other;
                break;
            }
            case 12:
            {
                cout << "Sequence: ";
                print_sequence(seq);
                cout << endl;
                break;
            }
            case 13:
            {
                cout << "Sequence: ";
                print_sequence(seq);
                cout << endl;
                if (buffer_sequence != nullptr)
                {
                    cout << "Buffer sequence: ";
                    print_sequence(buffer_sequence);
                    cout << endl;
                }
                break;
            }
            case 14:
            {
                seq->clear();
                cout << "Sequence cleared." << endl;
                break;
            }
            case 0:
            {
                delete seq;
                return;
            }
            default:
            {
                throw invalid_argument("Invalid choice");
                cout << endl;
            }
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

template <typename T>
void output_stack_menu(stack<T> *stack)
{
    int choice;
    T element;
    int index;
    int count;
    while (true)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n=== Stack Menu ===" << endl;
        cout << "Choose option: " << endl;
        cout << "1. Get top element " << endl;
        cout << "2. Delete top element " << endl;
        cout << "3. Add element to stack " << endl;
        cout << "4. Print stack " << endl;
        cout << "0. Return to previous menu" << endl;

        try
        {
            check_input(choice);
            switch (choice)
            {
            case 1:
            {
                cout << "Top element: " << stack->top() << endl;
                break;
            }
            case 2:
            {
                stack->pop();
                cout << "Top element deleted." << endl;
                break;
            }
            case 3:
            {
                cout << "Input element: ";
                cin >> element;
                stack->push(element);
                cout << "Element added." << endl;
                break;
            }
            case 4:
            {
                cout << "Stack: ";
                print_stack(stack);
                cout << endl;
                break;
            }
            case 0:
            {
                delete stack;
                return;
            }
            default:
            {
                throw invalid_argument("Invalid choice");
                cout << endl;
            }
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}