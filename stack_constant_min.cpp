#include <list>

using namespace std;

/*
Simply list implementation of min stack showing it's operations.  Internal data is hard - coded to ints
Operations Runtime:
min:  O(1)
push: O(1)
pop:  O(1)
*/

class MinStack {
public:
  void push(const int& i);
  void pop();
  int top();
  int min();

private:
  list<int> m_min;
  list<int> m_data;
};

void MinStack::push(const int& i)
{
  if (m_data.empty()) {
    m_min.push_front(i);
    m_data.push_front(i);
    return;
  }

  m_data.push_front(i);
  int curr_min = m_min.front();
  if (curr_min < i) {
    m_min.push_front(curr_min);
  } else m_min.push_front(i);
}

void MinStack::pop()
{
  if (m_data.empty())
    return;

  m_data.pop_front();
  m_min.pop_front();
}

int MinStack::top()
{
  if (m_data.empty()){
    //throw exception?
    return -1;
  }

  return m_data.front();
}

int MinStack::min() 
{
  if (m_min.empty()) {
    //throw exception?
    return -1;
  }

  return m_min.front();
}

int main() {

  MinStack ms;
  ms.push(1);       // min: 1   1  
  ms.push(2);       // min: 1   2 -> 1
  ms.push(0);       // min: 0   0 -> 2 -> 1
  ms.pop();         // min: 1   2 -> 1
  ms.push(5);       // min: 1   5 -> 2 -> 1
  ms.push(1);       // min: 1   1 -> 5 -> 2 -> 1
  ms.push(0);       // min: 0   0 -> 1 -> 5 -> 2 -> 1

  ms.pop();         // min: 1   1 -> 5 -> 2 -> 1
  ms.pop();         // min: 1   5 -> 2 -> 1

  return 0;
}