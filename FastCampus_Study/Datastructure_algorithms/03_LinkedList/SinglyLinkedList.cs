using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_LinkedList
{
    public class SinglyLinkedList<T>
    {
        private Node<T> m_head;

        public void AddLast(T data)
        {
            Node<T> node = new Node<T>(data);
            if(m_head == null)
            {
                m_head = node;
            }

            else
            {
                Node<T> last = m_head;

                while (last.Next != null)
                {
                    last = last.Next;
                }

                last.Next = node;
            }
        }

        public void AddFirst(T value)
        {
            Node<T> node = new Node<T>(value);

            node.Next = m_head;

            m_head = node;
        }

        public Node<T> Find(T value)
        {
            if (m_head != null)
            {
                Node<T> value_node = new Node<T>(value);
                Node<T> node = m_head;

                while(node != null)
                {
                    if (node.Data.Equals(value_node.Data))
                        break;

                    node = node.Next;

                }
                return node;
            }


            else
                return null;
        }

        public void AddAfter(Node<T> findNode, T value)
        {
            Node<T> node = new Node<T>(value);

            node.Next = findNode.Next;

            findNode.Next = node;
        }

        public void Remove(Node<T> removeNode)
        {
            Node<T> node = m_head;
            Node<T> nodeBefore = null;

            while(node != removeNode)
            {
                nodeBefore = node;
                node = node.Next;
            }

            if(nodeBefore == null)
            {
                m_head = removeNode.Next;
            }
            else
            {
                nodeBefore.Next = removeNode.Next;
                node = null;
            }

        }

        override
        public string ToString()
        {
            var temp = m_head;
            string data = "";

            while(temp != null)
            {
                if (!string.IsNullOrEmpty(data))
                    data += ",";
                data += temp.Data.ToString();

                temp = temp.Next;
            }

            return data;
        }
    }
}
