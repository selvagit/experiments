import urllib
from xml.etree.ElementTree import parse 
import time

def monitor ():
    u = urllib.urlopen('http://ctabustracker.com/bustime/map/getBusesForRoute.jsp?route=22')
    dat_xml = parse(u)
    id_check = [1394,1907,1268]

    dave_lat = 41.980262
    dave_lon = -87.6684452

    for bus in dat_xml.findall('bus'):
        id = int (bus.findtext('id'))

        for i in id_check:
            if id == i :
                lat = float (bus.findtext('lat')) 
                lon = float (bus.findtext('lon'))
                diff_lat = 69*abs(lat - dave_lat)
                diff_lon = 69*abs(lon - dave_lon)
                if diff_lat < 0.5 and diff_lon < 0.5:
                    print id, 'within half mile' 
                else:
                    print id,diff_lat

while True:
    monitor()
    print '--------'
    time.sleep(60)

           

