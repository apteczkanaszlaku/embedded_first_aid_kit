set(component_srcs "main.c")

idf_component_register(SRCS "${component_srcs}" "xbee.c" "wifi.c" "gpio.c" "http_server.c" "rc.c" "pn532.c" "sensors.c"
                       INCLUDE_DIRS "."
                       EMBED_FILES 
                       "webpage/Index.html" 
                       "webpage/register.html"
                       "webpage/jquery.js")
