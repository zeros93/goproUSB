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
url: /gopro/camera/analytics/set_client_info

``` Python
import requests

url = "http://172.27.199.51:8080/gopro/camera/analytics/set_client_info"
requests.request("GET", url)
```
