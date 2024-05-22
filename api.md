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
