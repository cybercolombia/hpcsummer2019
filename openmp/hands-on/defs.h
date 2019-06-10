#ifdef _OPENMP
    #include <omp.h>
    #define TRUE  1
    #define FALSE 0
#else
    #define omp_get_thread_num() 0
#endif

char *hByte(unsigned int bytes){
    char r_array[128];
    if (bytes <= 0) return "0 Bytes";
    else if (bytes >= 1073741824) snprintf(r_array, sizeof r_array, "%.2f GBytes", (((float) bytes)/1073741824));
    else if (bytes >= 1048576) snprintf(r_array, sizeof r_array, "%.2f MBytes", (((float) bytes)/1048576));
    else if (bytes >= 1024) snprintf(r_array, sizeof r_array, "%.2f KBytes", (((float) bytes)/1024));
    else snprintf(r_array, sizeof r_array, "%d Bytes", bytes);
    return r_array;
};

#define CREATEARRAY(_VAR,_TYPE,_SIZE,_ZEROVAL) \
	if ( (_VAR=(_TYPE*) malloc( _SIZE * sizeof(_TYPE) )) == NULL ) \
		perror("memory allocation for " #_VAR); \
	printf("\nNAME::   Array Name = " #_VAR "(" #_TYPE ")\n"); \
	printf("SIZE::   number of elements = %d\n",_SIZE); \
	for(int _IT_i = 0; _IT_i < _SIZE; _IT_i++) \
		_VAR[_IT_i] = _ZEROVAL; \
	printf("         Initialized with value: " #_ZEROVAL "\n"); \
	printf("         size of element = %d bytes\n",sizeof(_TYPE)); \
	printf("         size of array = %s\n",hByte(_SIZE * sizeof(_TYPE))); \
	printf("ARRAYS:: To free memory please use free(" #_VAR ")\n\n")

#define CREATEMATRIX(_VAR,_TYPE,_SIZEROWS,_SIZECOLS,_ZEROVAL) \
	if ( (_VAR=(_TYPE**) malloc( _SIZEROWS * sizeof(_TYPE*) )) == NULL ) \
		perror("pointer memory allocation for " #_VAR "*"); \
	if ( (_VAR[0]=(_TYPE*) malloc( _SIZEROWS * _SIZECOLS * sizeof(_TYPE) )) == NULL ) \
		perror("memory allocation for " #_VAR); \
	for( int _IT_i = 1; _IT_i < _SIZEROWS; _IT_i++ ) \
		_VAR[_IT_i] = _VAR[_IT_i-1] + _SIZECOLS; \
	printf("\nNAME::   Matrix Name = " #_VAR "(" #_TYPE ")\n"); \
	printf("SIZE::   number of elements = %d x %d\n",_SIZEROWS,_SIZECOLS); \
	for( int _IT_i = 0; _IT_i < _SIZEROWS; _IT_i++ ) \
		for( int _IT_j = 0; _IT_j < _SIZECOLS; _IT_j++ ) \
			_VAR[_IT_i][_IT_j] = _ZEROVAL; \
	printf("         Initialized with value: " #_ZEROVAL "\n"); \
	printf("         size of element = %d bytes\n",sizeof(_TYPE)); \
	printf("         size of matrix = %s\n",hByte(_SIZEROWS * _SIZECOLS * sizeof(_TYPE))); \
	printf("MATRIX:: To avoid memory leaks, free memory via a 2-step proc:\n"); \
	printf("\tfree(" #_VAR "[0]);\n\tfree(" #_VAR "), " #_VAR " = NULL;\n\n")

#define SETARRAY(_VAR,_SIZE,_ZEROVAL) \
    printf("MATRIX " #_VAR "(%d) / NEWVAL=" #_ZEROVAL "\n",_SIZE); \
    for( int _IT_i = 0; _IT_i < _SIZE; _IT_i++ ) \
        _VAR[_IT_i] = _ZEROVAL

#define SETMATRIX(_VAR,_SIZEROWS,_SIZECOLS,_ZEROVAL) \
    printf("MATRIX " #_VAR "(%d,%d) / NEWVAL=" #_ZEROVAL "\n",_SIZEROWS,_SIZECOLS); \
    for( int _IT_i = 0; _IT_i < _SIZEROWS; _IT_i++ ) \
        for( int _IT_j = 0; _IT_j < _SIZECOLS; _IT_j++ ) \
            _VAR[_IT_i][_IT_j] = _ZEROVAL

#define PRINTARRAY(_VAR,_SIZE) \
    printf("ARRAY(%d):: " #_VAR " = [",_SIZE); \
    for(int _IT_i = 0; _IT_i < _SIZE; _IT_i++) \
        printf("%lf, ",_VAR[_IT_i]); \
    printf("\b\b]\n\n")

#define PRINTMATRIX(_VAR,_SIZEROWS,_SIZECOLS) \
    printf("MATRIX(%d,%d):: " #_VAR " = [",_SIZEROWS,_SIZECOLS); \
    for(int _IT_i = 0; _IT_i < _SIZEROWS; _IT_i++) { \
        printf("\n\t("); \
        for(int _IT_j = 0; _IT_j < _SIZECOLS; _IT_j++) \
            printf("%lf, ",_VAR[_IT_i][_IT_j]); \
        printf("\b\b),"); \
    } \
    printf("\b\n]\n\n")

/*

    C implementation of a timer structure

*/
// We declare a type "SimpleTimer_t" as struct SimpleTimer
// This allows us to create timers in a simple syntax as:
// SimpleTimer t1;
typedef struct SimpleTimer SimpleTimer_t;
// Notice that we added a suffix "_t" for the type. This is
// a convention but it is not required

struct SimpleTimer{
    struct timeval start_time;
    struct timeval stop_time;
};

void SimpleTimer_start( SimpleTimer_t *thisT ){
    gettimeofday( &( thisT -> start_time ), NULL );
    thisT -> stop_time = thisT -> start_time;
};
void SimpleTimer_stop( SimpleTimer_t *thisT ){
    gettimeofday( &( thisT -> stop_time ), NULL );
};
void SimpleTimer_print( SimpleTimer_t *thisT ){
    printf("Time elapsed (msec): %lf\n",
        (( (thisT -> stop_time).tv_sec - (thisT -> start_time).tv_sec ) * 1000000LL +
        (thisT -> stop_time).tv_usec - (thisT -> start_time).tv_usec) * 0.001
    );
};


//-------------------Random Generator
class Crandom{
    unsigned long long int v;
public:
    Crandom(void) : v(4101842887655102017LL) { };
    Crandom(unsigned long long int j);
    ~Crandom(){};
    void set_seed(unsigned long long int j);
    inline unsigned long long int int64();
    inline double doub();
    inline unsigned int int32();
    inline int n(int a, int b);
    inline double r(void);
    inline double exp(double tau);
    inline double gaussian(double mu,double sigma);
};
Crandom::Crandom(unsigned long long int j) : v(4101842887655102017LL) {
    v ^= j;
    v = int64();
};
void Crandom::set_seed(unsigned long long int j) {
    v ^= j;
    v = int64();
};
inline unsigned long long int Crandom::int64(){
    v ^= v >> 21; v ^= v << 35; v ^= v >> 4;
    return v * 2685821657736338717LL;
};
inline double Crandom::doub(){
    return 5.42101086242752217E-20 * int64();
};
inline unsigned int Crandom::int32(){
    return (unsigned int)int64();
};
inline int Crandom:: n(int a, int b){
    return a + int64() % (b-a);
};
inline double Crandom:: r(void){
    return doub();
};
inline double Crandom::exp(double tau){
    double u;
    do u = doub(); while (u == 0.);
    return -log(u)/tau;
};
inline double Crandom::gaussian(double mu,double sig){
    static double storedval=0;
    double v1,v2,rsq,fac;
    if (storedval == 0.) {
        do {
            v1=2.0*doub()-1.0;
            v2=2.0*doub()-1.0;
            rsq=v1*v1+v2*v2;
        } while (rsq >= 1.0 || rsq == 0.0);
        fac=sqrt(-2.0*log(rsq)/rsq);
        storedval = v1*fac;
        return mu + sig*v2*fac;
    } else {
        fac = storedval;
        storedval = 0.;
        return mu + sig*fac;
    }
};


/*

    Usefull definitions and declarations

*/
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))
#define max(X, Y)  ((X) < (Y) ? (Y) : (X))

typedef double my_prec;
