# code chef- easy practice - hotel

nCases = int(raw_input())

for iter in range(nCases):
    nGuest = int(raw_input())
    arrivals = sorted(map(int, raw_input().split() ) )
    departures = sorted(map(int, raw_input().split() ) )
    
    maxGuests = 0
    guests = 0
    while arrivals:
        if arrivals[0] == departures[0]:
            # simultaneous arrival/departure doesn't affect guest count
            arrivals = arrivals[1:]
            departures = departures[1:]
        elif arrivals[0] < departures[0]:
            guests +=1
            if guests>maxGuests:
                maxGuests = guests
            arrivals = arrivals[1:]
        else:
            guests -=1
            departures = departures[1:]
    print maxGuests
            

    