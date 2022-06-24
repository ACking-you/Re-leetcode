#只对github.com使用代理，其他仓库不走代理
git config --global http.https://github.com.proxy http://127.0.0.1:7890
git config --global https.https://github.com.proxy https://127.0.0.1:7890
git add .
git commit -m "msg"
git push gitee master
git push github master
