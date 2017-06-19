#include "BarChart.h"
using namespace std;
namespace sict{


   std::ostream& BarChart::display(std::ostream& ostr)const {
      for (int i = 0; i < m_size; i++) {
         ostr << (i + 1) << ":";
         for (int j = 0; j< m_values[i]; j++) {
            ostr.put('=');
         }
         ostr << std::endl;
      }
      return ostr;
   }
   std::istream& BarChart::read(std::istream& istr) {
      for (int i = 0; i < m_size; i++) {
         cout << (i + 1) << "/" << m_size << ": ";
         istr >> m_values[i];
      }
      return istr;
   }


   int BarChart::max()const {
      int maxVal = m_values[0];
      for (int i = 1; i < m_size; i++) {
         if (maxVal < m_values[i]) maxVal = m_values[i];
      }
      return maxVal;
   }
   int BarChart::min()const {
      int minVal = m_values[0];
      for (int i = 1; i < m_size; i++) {
         if (minVal > m_values[i]) minVal = m_values[i];
      }
      return minVal;
   }
   int BarChart::average()const {
      int aver = 0;
      for (int i = 0; i < m_size; i++) {
         aver += m_values[i];
      }
      return aver / m_size;
   }
   BarChart& BarChart::merge(const BarChart& BC) {
      // allocate ints to the sum of the two chart values
      int* temp = new int[m_size + BC.m_size];
      int i;
      // set the beginning to the currect values
      for (i = 0; i < m_size; i++) {
         temp[i] = m_values[i];
      }
      // set the rest to the BC's values
      for (; i < m_size + BC.m_size; i++) {
         temp[i] = BC.m_values[i - m_size];
      }
      // update the size to the sum of the two.
      m_size += BC.m_size;
      // delete the old values
      delete[] m_values;
      // set the values to the new ones(pointed by temp)
      m_values = temp;
      return *this;
   }


}