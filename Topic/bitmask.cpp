/*
					NOT AND 	 OR 	XOR
	A 	B 	!A 	A&B 	A|B 	A^B
	0 	0 	1 	0 		0 		0
	0	  1	  1	  0		  1		  1
	1	  0	  0  	0	  	1	  	1
	1  	1  	0 	1	   	1 		0

X = 1152 = 	10010000000
Y = 1428 = 	10110010100

X & Y 	 = 	10010000000
X | Y 	 = 	10110010100
X ^ Y 	 = 	00100010100

X ^ 0 = X		
X ^ X = 0
A ^ B = C
A ^ C = B
B ^ C = A



(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E

X >> 1	 = 	1001000000 			Equals X/2
X >> 2	 = 	100100000 			Equals X/4
X << 1	 =  100100000000		Equals X*2
X << 2	 =  1001000000000		Equals X*4


X = 11010 = 26 = 2^1 + 2^3 + 2^4 = 2 + 8 + 16

X = 11010 = 26		// Last Bit shows Parity: Even / Odd
X = 11011 = 27

X % 2 = X & 1 = bit 0

Generally:	X%(2^n)  = X & (2^n -1)
(10010100) -1 = 10010011
n=2 
10010011 & 10010100= 10010000

Even test
	if(n%2 == 1)		

	if( (n&1) == 1)

*/



//iterative
void Binary_rep(int n)
{
    int i = 0;
    int b = 0;
    while(n != 0)
    {
        int p = n % 2;      // n & 1
        n /= 2;             //n >> 1
        b += p*pow(10,i);
        i++;

    }

    cout << b << '\n';
}



// recursive 

void printNumber(int n, int len)
{
	if(!len)
		return ;

	printNumber(n>>1, len-1);	// remove last bit
	cout<<(n&1);						// print last bit
}

void printnbr(int n)
{
    if(! n )
        return ;
		
    printnbr( n>>1 );
    cout<<(n&1);  
             
}


// Let's count bits


int countNumBits1(int mask) {	// O(bits Length)
	int ret = 0;	//1101001 -> 110100 -> 11010 -> 1101 -> 110 -> 11 -> 1 -> 0
	while (mask) {
		if(mask&1)
			ret++;
		mask >>= 1;
	}
	return ret;
}
__builtin_popcount(n);  // int 
__builtin_popcountl(n); //LL
//----> Complexity (log(n))

//len de mask= log2(n)+1 



// Exercise: how to verify a number is a power of 2 ???
// Exercise: getBit - setBit1 - setBit0 - flipBit
 

if (n&(n-1)==0)cout<<yes<<endl;
else cout<<no<<endl;



// Get bit
int getBit(int num, int idx) {
  return ((num >> idx) & 1) == 1;		// 110100, idx = 4  -->  110 & 1 = 0
}

int setBit1(int num, int idx) {
	return num | (1<<idx);
}

int setBit0(int num, int idx) {
	return num & ~(1<<idx);				// 110100, idx = 3  -->  110100 & ~000100 = 110100 & 111011
}

int flipBit(int num, int idx) {
	return num ^ (1<<idx);
}



/*
X-1 is very important!

X 	= 840 	= 01101001000
X-1 = 839 	= 01101000111		What happened? First bit 16=(2^4) is removed, and 15=2^4-1 is added.

X & (X-1) 	= 01101000000		first bit from right removed

X & ~(X-1) 	= 01101001000 & 10010111000 = 00000001000	value of 1<<SmaintestBitIdx
*/


int countNumBits2(int mask) {	//	O(bits Count)		__builtin_popcount
	int ret = 0;
	while (mask) 	{
		mask &= (mask-1);
		++ret;	// Simply remove the last bit and so on
	}
	return ret;
}


// len = 3: 000, 001, 010, 011, 100, 101, 110, 111

void printAllSubsets(int len)	
{
	for (int i = 0; i < (1<<len); ++i)
		printNumber(i, len);

	// For reversed order. Either reverse each item or work from big to small
	//for (int i = (1<<len); i >= 0 ; --i)
	//	printNumber(i, len);
}


// Be careful with operators precedence problems.
// X & 7 == 1 		is interpreted as 			X & (7 == 1)	--> (X & 7) == 1
// 1<<10 -1 		is interpreted as			= 1<<9			--> (1<<10) - 1

// Watch out from overflow
// 1 << 60 Fails. 1 is 32 bitInteger		-->		1LL << 60


// Much staff? Let's use STL!

#include <bitset>		// The power, speed and memory handling in one place

void STL() {
	const int N = 20;		// const
	string s = "000111";
	bitset<N> x(s);			// 00000000000000000111
	x.set();				// 11111111111111111111
	x.flip();				// 00000000000000000000

	x = 10;					// 00000000000000001010
	x |= 3;					// 00000000000000001011
	x = (x<<3);				// 00000000000001011000
	x = ~x;					// 11111111111110100111
	x.set(15, 0);			// 11110111111110100111
	x.set(15);				// 11111111111110100111
	x.flip(0);				// 11111111111110100110
	x.count();				// Returns the number of bits that are set.
	x.any();				// Returns true if any bits are set.
	x.none();				// Returns true if no bits are set.
	x.test(15);
	x.to_ulong();			// Returns an unsigned long represent mask

	// The most interesting
	if(x[2] == 0)
		;

	x[0] = 1;	// Set bit from most right to 1
	x[N-1] = 0;	// Set bit from most left to 0

	cout<<x<<"\n";			// display a string of N bits
}




































