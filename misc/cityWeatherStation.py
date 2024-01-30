# Use the HTTP GET method to retrieve information from a database of weather records. Query https://jsonmock.hacker rank.com/api/weather/search?name=(keyword} to search all the records where name has a keyword anywhere in its string value. 
# The query result is paginated and can be further accessed by appending to the query string &page=num where num is the page number.
# The query response from the API is a JSON with the following five fields:
# page: the current page
# per_page: the maximum number of results per page
# total. the total number of records in the search result
# total_pages. the total number of pages to query to get all the results
# data: an array of JSON objects that contain weather records

# The data field in the response contains a list of weather records with the following schema:
# name: the name of the city
# weather: temperature recorded
# status. an array of wind speed and humidity records
# Filter records to include a given keyword in the name parameter. Return an array such that each element is a string of comma-separated values: city_name, temperature, wind, humidity.
# For example,

# "name": "Adelaide",
# "weather": "15 degree"
# "status": [
# "Wind: 8Kmph"
# "Humidity: 61%"
# The JSON record is stored as Adelaide, 15,8,61
# Example JSON from API
# {
#   "page": 1,
#   "per_page": 10,
#   "total": 3,
#   "total_pages": 1,
#   "data": [
#     {
#       "name": "Dallas",
#       "weather": "12 degree",
#       "status": [
#         "Wind: 2Kmph",
#         "Humidity: 5%"
#       ]
#     },
#     {
#       "name": "Dallupura",
#       "weather": "10 degree",
#       "status": [
#         "Wind: 9Kmph",
#         "Humidity: 14%"
#       ]
#     },
#     {
#       "name": "Vallejo",
#       "weather": "1 degree",
#       "status": [
#         "Wind: 24Kmph",
#         "Humidity: 56%"
#       ]
#     }
#   ]
# }
# Return the list sorted by city name.
import requests


def weatherStation(keyword):
    baseUrl = "https://jsonmock.hackerrank.com/api/weather/search?name="+keyword
    
    res = requests.get(baseUrl)
    weatherData = res.json()
   
    
    # total = data["total"]
    total_pages = weatherData["total_pages"]
    filteredData = []
    # Iterate through each page for json data
    for i in range(1, total_pages+1):
        url = baseUrl + "&page=" + str(i)
        res = requests.get(url)
        weatherData = res.json()
        data = weatherData["data"]
        # iterate through each element in data
        for city in data:
            cityName = city["name"]
            weather = city["weather"].split()[0]
            status = city["status"]
            wind = city["status"][0]
            humidity = city["status"][1]
            # Parse & extract the numeric values from json
            
            wind_pos = wind.find(":")+2
            humidity_pos = humidity.find(":")+2
            windSpeed = wind[wind_pos:wind.find("K")]
            humidityValue = humidity[humidity_pos:humidity.find("%")]
            
             # format data and append results to array
            ans = cityName + "," + weather + "," + windSpeed + "," + humidityValue
            filteredData.append(ans)
    print(filteredData)


weatherStation("ab")
        
    
    

    
    