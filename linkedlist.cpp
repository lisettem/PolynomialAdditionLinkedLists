#include<iostream>
using namespace std;

struct Node {
	int number;
	int degree;
	Node* next;

};
class Link {

public:
	Link() { first = NULL; }
	void input(int n) {
		Node *dummy, *temp;

		temp = new Node;
		temp->number = n; 
		temp->next = NULL;

		if (first == NULL) {
			first = temp;
		}
		else {
			dummy = first;
			while (dummy->next != NULL)
				dummy = dummy->next;
			dummy->next = temp;
		}
	}
	Link add(Link l) {
		Node *addition1 = first;
		Node *addition2 = l.first;
		Link r; // resulting list
		while (addition1 != NULL)
		{
			r.input(addition1->number + addition2->number);
			addition1 = addition1->next;
			addition2 = addition2->next;

			return r;
		}
	}
	void print(int d) {
		Node *temp = first;
		while (temp != NULL) {
			if (temp->next != NULL)
				cout << temp->number << "x^" << d << " + ";
			else
				cout << temp->number << "x^" << d << " ";
			temp = temp->next;

			d--;
		}
	}
	int max(int m, int n)
	{
		return (m > n) ? m : n;
	}
private:
	Node *first;
};
int main() {
	Link list1, list2;
	Node deg, deg2; 
	int num, counter; 
	cout << "Enter the degree of your first polynomial:"; 
	cin >> deg.degree;

	counter = deg.degree;
	for (int i = 0; i <= deg.degree; i++)
	{
		cout << "Enter the coefficient for x^" << counter << ":";
		cin >> num;
		list1.input(num);
		counter--;
	}
	
	cout << "First list: =";
	list1.print(deg.degree);
	cout << endl << endl;

	int num2 = 0;
	
	cout << "Enter the degree of your second polynomial:";
	cin >> deg2.degree;
	int counter2 = deg2.degree;
	for (int i = 0; i <= deg2.degree; i++)
	{
		cout << "Enter the coefficient for x^" << counter2<< ":"; 
		cin >> num2; 
		list2.input(num2);
		counter2--; 

	}
	
	cout << "Second list: =";
	list2.print(deg2.degree);
	cout << endl << endl;

	Link addition = list1.add(list2);
	addition.print(addition.max(deg2.degree, deg.degree));

	system("pause");
	return 0;
}