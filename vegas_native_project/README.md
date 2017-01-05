**¥¥Ω®÷∏¡Ó**

*native*
cocos new -p com.LA.vegas -l cpp -d ./vegas_native_project
*js*
cocos new vegas_js -l js --no-native -d ./vegas_h5_project

----------
** compile boots **

bjam --toolset=msvc-12.0 --build-dir=F:/test_boost155/tmp --stagedir=F:/test_boost155 --with-system link=static threading=multi variant=debug,release runtime-link=static