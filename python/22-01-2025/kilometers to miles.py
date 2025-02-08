def kmToMiles(km):
    miles = km * 0.621371
    return miles

km = int(input('Enter the distance : '))
miles = kmToMiles(km)
print(f'{km} kilometers is equal to {miles} miles.')