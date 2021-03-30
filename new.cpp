#include <iostream> 
#include <cassert>
#include <functional>

	class HomeLibrary
    {
        private:
            struct Node
            {
                char   author[20]; 	
				char   book[20];
                Node* next{nullptr};
            };    
			
			Node *m_top{nullptr};

        public:
			~HomeLibrary();
            void pop();
            void push(char a_x, char a_y);
            void sort();
			void sort1();
            inline void show();
    };
	HomeLibrary::~HomeLibrary()
    {
        while (m_top)
        {
            this->pop();
        }
    }	
	void HomeLibrary::pop()
    {
        assert(m_top && "Minus books = (");
        auto temp{ m_top };
        m_top = m_top->next;
        delete temp;     
	}
	void HomeLibrary::push(char a_x, char a_y)
    {
        m_top = new Node{ a_x, a_y, m_top };
    }
	
	void HomeLibrary::sort()
	{
		if (m_top->next == NULL){return;}
			m_top = m_top->next;
			sort1();
	}
	void HomeLibrary::sort1()
	{
			if (m_top->next == NULL){return;}
			m_top = m_top->next;
			sort();
			if(strcmp(m_top.author,m_top->next.author) > 0)
			{
				auto temp{m_top};
				m_top = m_top -> next;
				temp -> next = temp;
			}
	}
	
	    void HomeLibrary::show()
    {
        std::function<void(const Node*)> printNode{};
        printNode = [&printNode](const Node* currentNode) -> void
        {
            if (currentNode)
            {
                printNode(currentNode->next);
                std::cout << "(" << currentNode->author << ", " << currentNode->book << ")\n";
            }
        };

        printNode(m_top);
    }

int main(int argc, char **argv)
{
	HomeLibrary shelf{};
	char i = 0;
	char author[20];
	char order[20];
	char book[20];
	std::cout << "InputBook\n";
	while (author != "stop"){
		for(i = 0; i < 20; ++i){std::cin >> author;}		
		for(i = 0; i < 20; ++i){std::cin >> book;}
		shelf.push(author,book);
	}
	shelf.sort();
	shelf.show();
	
}