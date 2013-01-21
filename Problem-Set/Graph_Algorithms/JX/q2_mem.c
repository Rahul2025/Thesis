#include <stdio.h>

 

int main()

{

int Dancers=0, Songs=0, SongList[500], n=0, m=0, c=0, PlayList[500], TotalPlaylist=0;

 

scanf ( "%d %d", &Dancers, &Songs);

for ( n = 0; n < Dancers; ++n)

{

scanf ( "%d", &c);

}

 

for ( n = 0; n < Dancers; ++n)

{

for ( m = 0; m < Songs; ++m)

{

scanf ( "%d", &c);

if ( n == 0)

SongList[m] = c;

else

SongList[m] += c;

}

}

 

do

{

// choose the song

for ( n = 0, c = 0, m = 0; n < Songs; ++n)

{

if ( !SongList[n])

continue;

if ( c < SongList[n])

{

c = SongList[n];

m = n;

//fprintf ( stdout, "chosen [%d] (%d)\n", n, c);

}

}

if ( !c)

break;

 

SongList[m] = 0;

PlayList[TotalPlaylist++] = m;

 

if ( TotalPlaylist >= 500)

break;

}

while ( 1);

 

fprintf ( stdout, "%d\n", TotalPlaylist);

for ( n = 0; n < TotalPlaylist; ++n)

{

fprintf ( stdout, "%d\n", PlayList[n]);

}


return 0;

}