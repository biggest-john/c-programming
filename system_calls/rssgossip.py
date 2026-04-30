"""
this is my own implementation of the code illustration of the rss exercise in the 
text head first C, I had to re-vamp it due to the fact that the style of python
used in the first code is actually quite outdated and many of the methods used 
deprecated and the rss sites are no longer hosted, hence the need to find out about
new rss pages on the web. Side note starting out, I did not even know what rss meant.
"""


import sys
import os 
import re
from urllib.request import urlopen, Request
import getopt
import unicodedata
from xml.dom import minidom

def usage():
    print("Usage: \npython rssgossip.py [-uh] <search-regexp>")

try: 
    opts, args = getopt.getopt(sys.argv[1:], "uh", ["urls", "help"]) # unlike c getopt, this one requires that flags come first cm
except getopt.GetoptError as err:
    print("error occurred: Detail:\n", str(err))
    usage()
    sys.exit(2)
    
include_urls = False 
for o,a in opts:
    if o in ("-u", "--urls"):
        include_urls = True
    elif o in ("-h", "--help"):
        usage()
        sys.exit()
    else:
        assert False, "unhandled option"
        
searcher = re.compile(args[0], re.IGNORECASE)

for url in os.environ["RSS_FEED"].split():
    header = {"User-Agent": "Mozilla/5.0"}
    req = Request(url, headers=header)

    try:
        with urlopen(req) as feed:
            dom = minidom.parse(feed)
            channel_tag = dom.getElementsByTagName("channel")[0]
                
            for node in channel_tag.getElementsByTagName("title"):
                title_txt = node.firstChild.wholeText
                # making the program ignore the search keyword and print out all new headline from every rss source.
                #if you wish to be able to set a search keyword uncomment the if-statement below and and indent every line up until
                # the except block under it.
                #if searcher.search(title_txt):
                title_txt = unicodedata.normalize("NFKD", title_txt)
                print("\n",title_txt)
                if include_urls:
                    parent = node.parentNode
                    link_to_source = parent.getElementsByTagName("link")[0].firstChild.wholeText
                    print(f"\t{link_to_source}")

    except Exception as e:
        print(e)
        sys.exit(1)
