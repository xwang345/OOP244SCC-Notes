#ifndef SICT_BARCHART_H__
#define SICT_BARCHART_H__
#include <iostream>
namespace sict {
   class BarChart {
      int* m_values;
      int m_size;
   public:
      BarChart(int size = 1); 
      BarChart(const int values[], int size);
      BarChart(const BarChart& BC);
      BarChart& operator=(const BarChart& BC);
      std::ostream& display(std::ostream& ostr = std::cout)const;
      std::istream& read(std::istream& istr = std::cin);
      int max()const;
      int min()const;
      int average()const;
      BarChart& merge(const BarChart& BC);
      ~BarChart();
   };
}



#endif // !SICT_BARCHART_H__
