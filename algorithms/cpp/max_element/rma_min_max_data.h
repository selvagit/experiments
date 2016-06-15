#include <iostream>
#include <sstream>
#include <cstring>

#include <cstdint>


struct __attribute__((__packed__)) RMAMinMaxData 
{
    uint8_t  _max;
    uint8_t  _min;
    uint8_t  _avg;
    uint8_t _curr;
    uint32_t _frame_size;
    uint32_t _curr_index;
    uint64_t _data;
    uint32_t _dummy;
    const static uint32_t ONE_MIN  = 60; // 60(sec)
    const static uint32_t ONE_HOUR = 3600; // 60(sec)*60(min)
    const static uint32_t ONE_DAY  = 86400; // 60(sec)*60(min)*24(hour)
    const static uint32_t ONE_WEEK = 604800; // 60(sec)*60(min)*24(hour)*7(Day)

    RMAMinMaxData():_max(0),_min(100),_avg(0),_frame_size(ONE_MIN),_curr_index(1) 
    {
        _data = 0;
    }

    RMAMinMaxData(int frame_size):_max(0),_min(100),_avg(0),_frame_size(frame_size),_curr_index(1)
    {
        _data = 0 ;
    }

    ~RMAMinMaxData()
    {
    }

    void insert(uint8_t curr_sample) 
    {
        if ( (_curr_index % _frame_size) == 0 )
        {
            _avg = _data/_curr_index;
        }

        _curr = curr_sample;
        _data += curr_sample;
        _curr_index++;

        uint32_t _lower = (uint32_t) (_data & 0xffffffff);
        uint32_t _higher = (uint32_t) ((_data >>32)& 0xffffffff);
        //RMA_PRINT_CONSOLE("'Modi'fied _curr = %d _data(lower) = %x _data(higher) = %x_curr_index = %d \r\n",_curr,_lower,_higher,_curr_index);
        std::cout << "'Modi'fied _curr = "<<static_cast<unsigned int>(_curr) << " _data(lower) =" << _lower << " data(higher) = "<< _higher <<" _curr_index = " << _curr_index << std::endl;

        if ( _max <= curr_sample)
        {
            _max = curr_sample;
        }

        if ( _min > curr_sample)
        {
            _min = curr_sample;
        }

        if (_curr_index > ONE_DAY)
        {
            _curr_index = 1;
            _data = 0;
        }
    }

    uint8_t get_max()
    {
        return _max;
    }

    uint8_t get_min()
    {
        return _min;
    }

    uint8_t get_avg()
    {
        return _avg;
    }

    uint8_t get_curr()
    {
        return _curr;
    }
};

