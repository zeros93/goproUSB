# GoPro API

- Version
    - Python 3.6.9
    - pip 21.3.1 from /usr/local/lib/python3.6/dist-packages/pip (python 3.6)
    - require package
        - requests

http requests에 대한 응답으로 `<Response [200]>`이면 정상적으로 처리가 된 것이고, 
`<Response [400]>` 또는 `<Response [404]>`은 오류가 발생한 것으로 url이나 변수를 확인해야 함.

## Analytics

### Set Client as Third Party
    method: GET
    url: `/gopro/camera/analytics/set_client_info`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/analytics/set_client_info"
requests.request("GET", url)
```

``` C
CURL *hnd = curl_easy_init();

curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "GET");
curl_easy_setopt(hnd, CURLOPT_URL, "http://172.27.199.51:8080/gopro/camera/analytics/set_client_info");

CURLcode ret = curl_easy_perform(hnd);
```

## Control

### Configure Turbo Transfer
    method: GET
    url: `/gopro/media/turbo_transfer`
    parameters: p
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/turbo_transfer"
querystring = {"p": "1"}
requests.request("GET", url, params=querystring)
```

### Enable Wired camera control over USB
    method: GET
    url: `/gopro/camera/control/wired_usb`
    parameters: p
    Responses: 404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/control/wired_usb"
querystring = {"p":"0"}
requests.request("GET", url, params=querystring)
```

### Keep Alive
    method: GET
    url: `/gopro/camera/keep_alive`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/keep_alive"
requests.request("GET", url)
```

### Set Camera Control Status
    method: GET
    url: `/gopro/camera/control/set_ui_controller`
    parameters: p
    Responses: 404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/control/set_ui_controller"
querystring = {"p":"0"}
requests.request("GET", url, params=querystring)
```

### Set Date / Time
    method: GET
    url: `/gopro/camera/set_date_time`
    parameters:
        date
        time
        tzone - Not supported on: Hero 9 Black, Hero 10 Black
        dst - Not supported on: Hero 9 Black, Hero 10 Black
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/set_date_time"
querystring = {"date":"2024_05_23", "time":"11_36_13"}
requests.request("GET", url, params=querystring)
```

### Set Digital Zoom
    method: GET
    url: `/gopro/camera/digital_zoom`
    parameters: percent
    Responses: 500

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/digital_zoom"
querystring = {"percent":"50"}
requests.request("GET", url, params=querystring)
```

### Set Shutter
    method: GET
    url: `/gopro/camera/shutter/`
    parameters: mode=[start, stop]
    Responses: 404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/shutter/start"
requests.request("GET", url)
url = "http://172.27.199.51:8080/gopro/camera/shutter/stop"
requests.request("GET", url)
```

## Hilights

### Hilight a Media File
### Hilight While Recording
### Remove Hilight

## Media

### Delete All Files
    method: GET
    url: `/gp/gpControl/command/storage/delete/all`
    Responses: 

``` Python
import requests

url = "http://172.27.199.51:8080/gp/gpControl/command/storage/delete/all"
requests.request("GET", url)
```

### Delete Grouped Media Item
    method: GET
    url: `/gp/gpControl/command/storage/delete/group`
    parameters: p
    Responses: 200/500

``` Python
import requests

url = "http://172.27.199.51:8080/gp/gpControl/command/storage/delete/group?p=100GOPRO/G0016880.JPG"
requests.request("GET", url)
```

### Delete Single Media Item
    method: GET
    url: `/gopro/media/delete/file`
    parameters: path
    Responses: 200/400

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/delete/file?path=100GOPRO/GOPR0011.JPG"
requests.request("GET", url)
```

### Download a Media File

### Get Last Captured Media
HERO 12 Black only

### Get Media File GPMF
    method: GET
    url: `/gopro/media/gpmf`
    parameters: path
    Responses: 200/404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/gpmf?path=100GOPRO/GOPR0015.JPG"
response = requests.request("GET", url)
print(response.text)
```

### Get Media File Info
    method: GET
    url: `/gopro/media/info`
    parameters: path
    Responses: 200/404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/info?path=100GOPRO/GOPR0015.JPG"
response = requests.request("GET", url)
print(response.text)
```

### Get Media File Screennail

### Get Media File Telemetry
    method: GET
    url: `/gopro/media/telemetry`
    parameters: path
    Responses: 400

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/telemetry?path=100GOPRO/GOPR0015.JPG"
requests.request("GET", url)
```

### Get Media File Thumbnail
    method: GET
    url: `/gopro/media/thumbnail`
    parameters: path
    Responses: 200/404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/thumbnail?path=100GOPRO/GOPR0015.JPG"
requests.request("GET", url)
```

### Get Media List
    method: GET
    url: `/gopro/media/list`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/media/list"
response = requests.request("GET", url)
print(response.text)
```

## Presets

### Get Available Presets
    method: GET
    url: `/gopro/camera/presets/get`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/presets/get"
response = requests.request("GET", url)
print(response.text)
```

### Load Preset by ID

### Load Preset Group by ID

### Update Custom Preset
HERO 12 Black only

## Preview Stream

### Start Preview Stream
    method: GET
    url: `/gopro/camera/stream/start`
    parameters: port
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/stream/start"
querystring = {"port":"8556"}
requests.request("GET", url, params=querystring)
```

### Stop Preview Stream
    method: GET
    url: `/gopro/camera/stream/stop`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/stream/stop"
requests.request("GET", url)
```

## Query

### Get Camera State
    method: GET
    url: `/gopro/camera/state`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/state"
response = requests.request("GET", url)
print(response.text)
```

### Get Date / Time
    method: GET
    url: `/gopro/camera/get_date_time`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/get_date_time"
response = requests.request("GET", url)
print(response.text)
```

### Get Hardware Info
    method: GET
    url: `/gopro/camera/info`
    Responses: 404

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/info"
requests.request("GET", url)
```

### Get Last Captured Media
HERO 12 Black only

### Get Open GoPro Version
    method: GET
    url: `/gopro/version`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/version"
response = requests.request("GET", url)
print(response.text)
```

## settings

### Auto Power Down (59)
    method: GET
    url: `/gopro/camera/setting?setting=59`
    parameters:
        setting: 59
        option: [0, 4, 6, 7]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=59&option=7"
requests.request("GET", url)
```

### Bit Depth (183)
HERO 12 Black only

### Controls (175)
HERO 11/12 Black only

### Easy Mode Speed (176)
HERO 11/12 Black only

### Enable Night Photo (177)
HERO 11 Black only

### Frames Per Second (3)
    method: GET
    url: `/gopro/camera/setting?setting=3`
    parameters:
        setting: 3
        option: [0, 1, 2, 5, 6, 8, 9, 10, 13]
    Responses: 400

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=3&option=10"
requests.request("GET", url)
```

### Framing (193)
HERO 12 Black only

### GPS (83)
HERO 9/10/11 Black only

    method: GET
    url: `/gopro/camera/setting?setting=83`
    parameters:
        setting: 83
        option: [0, 1]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=83&option=1"
requests.request("GET", url)
```

### HindSight (167)
HERO 9/10/11/12 Black only

    method: GET
    url: `/gopro/camera/setting?setting=167`
    parameters:
        setting: 167
        option: [2, 3, 4]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=167&option=2"
requests.request("GET", url)
```

### Hypersmooth (135)
    method: GET
    url: `/gopro/camera/setting?setting=135`
    parameters:
        setting: 135
        option: [0-4, 100]
    Responses: 403

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=135&option=2"
requests.request("GET", url)
```

### Lapse Mode (187)
HERO 12 Black only

### Max Lens (162)
HERO 9/10/11 Black only

    method: GET
    url: `/gopro/camera/setting?setting=162`
    parameters:
        setting: 162
        option: [0, 1]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=162&option=0"
requests.request("GET", url)
```

### Max Lens Mod (189)
HERO 12 Black only

### Max Lens Mod Enable (190)
HERO 12 Black only

### Media Format (128)
HERO 9/10/11/12 Black only

    method: GET
    url: `/gopro/camera/setting?setting=128`
    parameters:
        setting: 128
        option: [13, 20, 21, 26]
    Responses: 403

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=128&option=13"
requests.request("GET", url)
```

### Multi Shot Aspect Ratio (192)
HERO 12 Black only

### Photo Horizon Leveling (151)
HERO 11 Black only

### Photo Interval Duration (172)
HERO 12 Black only

### Photo Lens (122)
HERO 9/10/11/12 Black only

    method: GET
    url: `/gopro/camera/setting?setting=122`
    parameters:
        setting: 122
        option: [19, 100-102]
    Responses: 403

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=122&option=100"
requests.request("GET", url)
```

### Photo Mode (191)
HERO 12 Black only

### Photo Single Interval (171)
HERO 12 Black only

### Profiles (184)
HERO 12 Black only

### Setup Anti-Flicker (134)
    method: GET
    url: `/gopro/camera/setting?setting=134`
    parameters:
        setting: 134
        option: [2, 3]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=134&option=2"
requests.request("GET", url)
```

### System Video Mode (180)
HERO 11 Black only

### Time Lapse Digital Lenses (123)
HERO 9/10/11/12 Black only

    method: GET
    url: `/gopro/camera/setting?setting=123`
    parameters:
        setting: 123
        option: [19, 100-102]
    Responses: 403

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=123&option=101"
requests.request("GET", url)
```

### Trail Length (179)
HERO 11/12 Black only

### Video Aspect Ratio (108)
HERO 12 Black only

### Video Bit Rate (182)
HERO 12 Black only

### Video Easy Mode (186)
HERO 12 Black only

### Video Horizon Leveling (150)
HERO 11 Black only

### Video Lens (121)
    method: GET
    url: `/gopro/camera/setting?setting=121`
    parameters:
        setting: 121
        option: [0, 2-4, 7-11]
    Responses: 403

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=121&option=7"
requests.request("GET", url)
```

### Video Performance Mode (173)
HERO 10 Black only

### Video Resolution (2)
    method: GET
    url: `/gopro/camera/setting?setting=2`
    parameters:
        setting: 2
        option: [1, 4, 6, 7, 9, 18, 24-28, 100, 107-111]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=2&option=24"
requests.request("GET", url)
```

### Webcam Digital Lenses (43)
    method: GET
    url: `/gopro/camera/setting?setting=43`
    parameters:
        setting: 43
        option: [0, 2-4]
    Responses: 500

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/setting?setting=43&option=3"
requests.request("GET", url)
```

### Wireless Band (178)
HERO 11/12 Black only

## Webcam

### Enter Webcam Preview
    method: GET
    url: `/gopro/webcam/preview`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/preview"
requests.request("GET", url)
```

### Exit Webcam Mode
    method: GET
    url: `/gopro/webcam/exit`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/exit"
requests.request("GET", url)
```

### Get Webcam Status
    method: GET
    url: `/gopro/webcam/status`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/status"
response = requests.request("GET", url)
print(response.text)
```

### Get Webcam Version
    method: GET
    url: `/gopro/webcam/version`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/version"
response = requests.request("GET", url)
print(response.text)
```

### Start Webcam
    method: GET
    url: `/gopro/webcam/start`
    parameters:
        res: [4, 7, 12]
        fov: [0, 2-4]
        port
        protocol: ["RTSP", "TS"]
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/start"
querystring = {"res":"12","fov":"0","port":"8556","protocol":"RTSP"}
requests.request("GET", url, params=querystring)
```

### Stop Webcam
    method: GET
    url: `/gopro/webcam/stop`
    Responses: 200

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/webcam/stop"
requests.request("GET", url)
```

