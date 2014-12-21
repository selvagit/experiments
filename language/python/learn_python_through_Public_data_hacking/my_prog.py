import urllib
from xml.etree.ElementTree import parse

#u = urllib.urlopen('http://ctabustracker.com/bustime/map/getBusesForRoute.jsp?route=22')
#data = u.read()
#f = open('rt22.xml','wb')
#f.write(data)
#f.close()

doc = parse ('rt22.xml')
dave_lat = 41.980262
dave_lon = -87.6684452

for bus in doc.findall('bus'):
    lat = float (bus.findtext('lat'))

    if lat >  dave_lat:
        d = bus.findtext('d')
        if d.find('North') >= 0 :
            print bus.findtext('id') , lat 

