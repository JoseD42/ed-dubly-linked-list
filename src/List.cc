#include "List.hh"
#include<iostream>

List::List()
{
}

List::~List()
{
}

void List::AddFront(Book* book)
{
    Node* node{new Node(book)};
    if(IsEmpty())
    {
        head = node;
    }
    else
    {
        if(!tail)
        {
            tail = head;
            head = node;
            head->next = tail;
            tail->back = head;
        }
        else
        {
            node->next = head;
            head = node;
            head->next->back = head;
        }
        
    }
}

void List::AddBack(Book* book)
{
    Node* node{new Node(book)};
    if(IsEmpty())
    {
        tail = node;
    }
    else
    {
        if(!head)
        {
            head = tail;
            tail = node;
            tail->back = head;
            head->next = tail;
        }
        else
        {
            node->back = tail;
            tail = node;
            tail->back->next = tail;
        }
        
    }
}

void List::RemoveFront()
{
    if(!head)
    {
        std::cout << "Lista vacia" << std::endl;
        return;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
}
void List::RemoveBack()
{
    if(!tail)
    {
        std::cout << "Lista vacia" << std::endl;
        return;
    }
    else
    {
        Node* temp = tail;
        tail = tail->back;
        delete temp;
    }
}

Book* List::GetFront() const
{
    return head->book;
}
Book* List::GetBack() const
{
    return tail->book;
}
bool List::IsEmpty() const
{
    return !head && !tail;
}
void List::PrintFront()
{
    if(IsEmpty())
    {
        std::cout << "Lista vacia" << std::endl;
    }
    else
    {
        Node* temp{head};

        while (temp)
        {
            std::cout << "Nombre del libro:" << temp->book->GetName() << std::endl;
            std::cout << "Autor del libro:" << temp->book->GetAuthor() << std::endl;
            temp = temp->next;
        }
        
    }
    
}
void List::PrintBack()
{
    if(IsEmpty())
    {
        std::cout << "Lista vacia" << std::endl;
    }
    else
    {
        Node* temp{tail};

        while (temp)
        {
            std::cout << "Nombre del libro:" << temp->book->GetName() << std::endl;
            std::cout << "Autor del libro:" << temp->book->GetAuthor() << std::endl;
            temp = temp->back;
        }
    }
}