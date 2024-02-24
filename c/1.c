#include <time.h>
#include <stdio.h>

int main(void) {
    struct tm st;
    time_t tod;
    st.tm_year = 70; // from 1970 onward!
    st.tm_mon = 6;
    st.tm_mday = 5;
    st.tm_hour = 10;
    st.tm_min = 3;
    st.tm_sec = 5;
    st.tm_isdst = 0;

    tod = mktime(&st);
    printf(ctime(&tod));
}
