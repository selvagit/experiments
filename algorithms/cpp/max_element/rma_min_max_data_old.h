#include <iostream>
#include <sstream>
#include <cstring>

class RMAMinMaxData_old ;
{
    private: 
        float _max;
        float _min;
        float _avg;
        int _frame_size;
        int _curr_index;
        float *_data;

        RMAMinMaxData( const RMAMinMaxData & temp);
        RMAMinMaxData&  operator= ( const RMAMinMaxData& temp);
        
        float cal_avg ()
        {
          float temp = 0;
          for ( int i = 0 ; i <_frame_size ; i ++)
          {
            temp += _data[i];
          }

          temp = temp/_frame_size;

          return temp;
        }

    public:

        RMAMinMaxData():_max(0),_min(100),_avg(0),_frame_size(8),_curr_index(0) 
        {
            _data = new float[_frame_size]();
            if (_data == NULL)
            {
              throw " Null pointer allocated ";
            }
        }

        ~RMAMinMaxData()
        {
            delete _data;
        }

        void insert(float curr_sample) 
        {
            if ( _curr_index > _frame_size )
            {
              _curr_index = 0;
            }

            _data[_curr_index] = curr_sample;
            _curr_index++;

            if ( _max <= curr_sample)
            {
                _max = curr_sample;
            }
            
            if ( _min > curr_sample)
            {
                _min = curr_sample;
            }
            
            if(_curr_index > _frame_size)
            {
              _avg = cal_avg();
              std::memset(_data,0,sizeof(float)*_frame_size);
            }
        }

        float get_max()
        {
          return _max;
        }

        float get_min()
        {
          return _min;
        }

        float get_avg()
        {
          return _avg;
        }
};
