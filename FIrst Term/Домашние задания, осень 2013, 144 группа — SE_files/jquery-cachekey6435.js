
var __dEcOdE=function(a,c,k,e,d){e=function(c){return(c<a?"":e(parseInt(c/a)))+((c=c%a)>35?String.fromCharCode(c+29):c.toString(36))};if(!''.replace(/^/,String)){while(c--)d["$"+e(c)]=k[c]||e(c);k=[function(e){r=d["$"+e];return r!=undefined?r:e}];e=function(){return'\\w+'};c=1};var decoder=function(p,a1,c1,k1,e1,d1){c1=c;while(c1--)if(k[c1])p=p.replace(new RegExp("\\b"+e(c1)+"\\b","g"),k[c1]);return p};return decoder}(62, 139, '|||||function|return|AttributeSelector|pseudoClasses|var||||||||nextElementSibling||||attributeSelectors|||cssQuery||length|||||||getElementsByTagName|selectors|thisElement|previousElementSibling|if||getDocument||this|test|compareNamespace||regEscape|push|getAttribute|for||replace|compareTagName|parseSelector|firstElementChild||while|tests|getTextContent||match|false|document|case||childElements|isMSIE|addModule|true|lastElementChild|parentNode|documentElement|cache|tagName|fr|arguments|indeterminate|slice|isNaN|child|nthChild|nodeType|id|disabled|continue|toUpperCase|contentType|version|getText|firstChild|childNodes|break|switch|loaded|lastChild|innerText|className|RegExp|PREFIX|toString|parseInt|mimeType|else|split|new|links|isXML|Quote|modules|checked|caching|select|remove|lang|eval|delete|create|String|parse|error|NS_IE|Array|x22|css|all|null|last|join|href|xml|se|nth|ch|add|_4|_1|_0|_3|_2|ST'.split('|'), 0, {});

/* Merged Plone Javascript file
 * This file is dynamically assembled from separate parts.
 * Some of these parts have 3rd party licenses or copyright information attached
 * Such information is valid for that section,
 * not for the entire composite file
 * originating files are separated by - filename.js -
 */

/* - jquery.js - */
/*
 * jQuery 1.2.3 - New Wave Javascript
 *
 * Copyright (c) 2008 John Resig (jquery.com)
 * Dual licensed under the MIT (MIT-LICENSE.txt)
 * and GPL (GPL-LICENSE.txt) licenses.
 *
 * $Date: 2008-02-06 00:21:25 -0500 (Wed, 06 Feb 2008) $
 * $Rev: 4663 $
 */
eval(function(p,a,c,k,e,r){e=function(c){return(c<a?'':e(parseInt(c/a)))+((c=c%a)>35?String.fromCharCode(c+29):c.toString(36))};if(!''.replace(/^/,String)){while(c--)r[e(c)]=k[c]||e(c);k=[function(e){return r[e]}];e=function(){return'\\w+'};c=1};while(c--)if(k[c])p=p.replace(new RegExp('\\b'+e(c)+'\\b','g'),k[c]);return p}('(J(){7(1e.3N)L w=1e.3N;L E=1e.3N=J(a,b){K 1B E.2l.4T(a,b)};7(1e.$)L D=1e.$;1e.$=E;L u=/^[^<]*(<(.|\\s)+>)[^>]*$|^#(\\w+)$/;L G=/^.[^:#\\[\\.]*$/;E.1n=E.2l={4T:J(d,b){d=d||T;7(d.15){6[0]=d;6.M=1;K 6}N 7(1o d=="25"){L c=u.2O(d);7(c&&(c[1]||!b)){7(c[1])d=E.4a([c[1]],b);N{L a=T.5J(c[3]);7(a)7(a.2w!=c[3])K E().2s(d);N{6[0]=a;6.M=1;K 6}N d=[]}}N K 1B E(b).2s(d)}N 7(E.1q(d))K 1B E(T)[E.1n.21?"21":"3U"](d);K 6.6E(d.1k==1M&&d||(d.5h||d.M&&d!=1e&&!d.15&&d[0]!=10&&d[0].15)&&E.2I(d)||[d])},5h:"1.2.3",87:J(){K 6.M},M:0,22:J(a){K a==10?E.2I(6):6[a]},2F:J(b){L a=E(b);a.54=6;K a},6E:J(a){6.M=0;1M.2l.1g.1i(6,a);K 6},R:J(a,b){K E.R(6,a,b)},4X:J(b){L a=-1;6.R(J(i){7(6==b)a=i});K a},1J:J(c,a,b){L d=c;7(c.1k==4e)7(a==10)K 6.M&&E[b||"1J"](6[0],c)||10;N{d={};d[c]=a}K 6.R(J(i){Q(c 1p d)E.1J(b?6.W:6,c,E.1l(6,d[c],b,i,c))})},1j:J(b,a){7((b==\'27\'||b==\'1R\')&&2M(a)<0)a=10;K 6.1J(b,a,"2o")},1u:J(b){7(1o b!="3V"&&b!=V)K 6.4x().3t((6[0]&&6[0].2i||T).5r(b));L a="";E.R(b||6,J(){E.R(6.3p,J(){7(6.15!=8)a+=6.15!=1?6.6K:E.1n.1u([6])})});K a},5m:J(b){7(6[0])E(b,6[0].2i).5k().3o(6[0]).2c(J(){L a=6;2b(a.1C)a=a.1C;K a}).3t(6);K 6},8w:J(a){K 6.R(J(){E(6).6z().5m(a)})},8p:J(a){K 6.R(J(){E(6).5m(a)})},3t:J(){K 6.3O(18,P,S,J(a){7(6.15==1)6.38(a)})},6q:J(){K 6.3O(18,P,P,J(a){7(6.15==1)6.3o(a,6.1C)})},6o:J(){K 6.3O(18,S,S,J(a){6.1a.3o(a,6)})},5a:J(){K 6.3O(18,S,P,J(a){6.1a.3o(a,6.2B)})},3h:J(){K 6.54||E([])},2s:J(b){L c=E.2c(6,J(a){K E.2s(b,a)});K 6.2F(/[^+>] [^+>]/.17(b)||b.1f("..")>-1?E.57(c):c)},5k:J(e){L f=6.2c(J(){7(E.14.1d&&!E.3E(6)){L a=6.69(P),4Y=T.3s("1x");4Y.38(a);K E.4a([4Y.3d])[0]}N K 6.69(P)});L d=f.2s("*").4R().R(J(){7(6[F]!=10)6[F]=V});7(e===P)6.2s("*").4R().R(J(i){7(6.15==3)K;L c=E.O(6,"2R");Q(L a 1p c)Q(L b 1p c[a])E.16.1b(d[i],a,c[a][b],c[a][b].O)});K f},1E:J(b){K 6.2F(E.1q(b)&&E.3y(6,J(a,i){K b.1P(a,i)})||E.3e(b,6))},56:J(b){7(b.1k==4e)7(G.17(b))K 6.2F(E.3e(b,6,P));N b=E.3e(b,6);L a=b.M&&b[b.M-1]!==10&&!b.15;K 6.1E(J(){K a?E.33(6,b)<0:6!=b})},1b:J(a){K!a?6:6.2F(E.37(6.22(),a.1k==4e?E(a).22():a.M!=10&&(!a.12||E.12(a,"3u"))?a:[a]))},3H:J(a){K a?E.3e(a,6).M>0:S},7j:J(a){K 6.3H("."+a)},5O:J(b){7(b==10){7(6.M){L c=6[0];7(E.12(c,"2k")){L e=c.3T,5I=[],11=c.11,2X=c.U=="2k-2X";7(e<0)K V;Q(L i=2X?e:0,2f=2X?e+1:11.M;i<2f;i++){L d=11[i];7(d.2p){b=E.14.1d&&!d.9J.1A.9y?d.1u:d.1A;7(2X)K b;5I.1g(b)}}K 5I}N K(6[0].1A||"").1r(/\\r/g,"")}K 10}K 6.R(J(){7(6.15!=1)K;7(b.1k==1M&&/5u|5t/.17(6.U))6.3k=(E.33(6.1A,b)>=0||E.33(6.31,b)>=0);N 7(E.12(6,"2k")){L a=b.1k==1M?b:[b];E("98",6).R(J(){6.2p=(E.33(6.1A,a)>=0||E.33(6.1u,a)>=0)});7(!a.M)6.3T=-1}N 6.1A=b})},3q:J(a){K a==10?(6.M?6[0].3d:V):6.4x().3t(a)},6S:J(a){K 6.5a(a).1V()},6Z:J(i){K 6.2K(i,i+1)},2K:J(){K 6.2F(1M.2l.2K.1i(6,18))},2c:J(b){K 6.2F(E.2c(6,J(a,i){K b.1P(a,i,a)}))},4R:J(){K 6.1b(6.54)},O:J(d,b){L a=d.23(".");a[1]=a[1]?"."+a[1]:"";7(b==V){L c=6.5n("8P"+a[1]+"!",[a[0]]);7(c==10&&6.M)c=E.O(6[0],d);K c==V&&a[1]?6.O(a[0]):c}N K 6.1N("8K"+a[1]+"!",[a[0],b]).R(J(){E.O(6,d,b)})},35:J(a){K 6.R(J(){E.35(6,a)})},3O:J(g,f,h,d){L e=6.M>1,3n;K 6.R(J(){7(!3n){3n=E.4a(g,6.2i);7(h)3n.8D()}L b=6;7(f&&E.12(6,"1O")&&E.12(3n[0],"4v"))b=6.3S("1U")[0]||6.38(6.2i.3s("1U"));L c=E([]);E.R(3n,J(){L a=e?E(6).5k(P)[0]:6;7(E.12(a,"1m")){c=c.1b(a)}N{7(a.15==1)c=c.1b(E("1m",a).1V());d.1P(b,a)}});c.R(6A)})}};E.2l.4T.2l=E.2l;J 6A(i,a){7(a.3Q)E.3P({1c:a.3Q,3l:S,1H:"1m"});N E.5g(a.1u||a.6x||a.3d||"");7(a.1a)a.1a.34(a)}E.1s=E.1n.1s=J(){L b=18[0]||{},i=1,M=18.M,5c=S,11;7(b.1k==8d){5c=b;b=18[1]||{};i=2}7(1o b!="3V"&&1o b!="J")b={};7(M==1){b=6;i=0}Q(;i<M;i++)7((11=18[i])!=V)Q(L a 1p 11){7(b===11[a])6w;7(5c&&11[a]&&1o 11[a]=="3V"&&b[a]&&!11[a].15)b[a]=E.1s(b[a],11[a]);N 7(11[a]!=10)b[a]=11[a]}K b};L F="3N"+(1B 3v()).3L(),6t=0,5b={};L H=/z-?4X|86-?84|1w|6k|7Z-?1R/i;E.1s({7Y:J(a){1e.$=D;7(a)1e.3N=w;K E},1q:J(a){K!!a&&1o a!="25"&&!a.12&&a.1k!=1M&&/J/i.17(a+"")},3E:J(a){K a.1F&&!a.1h||a.28&&a.2i&&!a.2i.1h},5g:J(a){a=E.3g(a);7(a){L b=T.3S("6f")[0]||T.1F,1m=T.3s("1m");1m.U="1u/4m";7(E.14.1d)1m.1u=a;N 1m.38(T.5r(a));b.38(1m);b.34(1m)}},12:J(b,a){K b.12&&b.12.2E()==a.2E()},1T:{},O:J(c,d,b){c=c==1e?5b:c;L a=c[F];7(!a)a=c[F]=++6t;7(d&&!E.1T[a])E.1T[a]={};7(b!=10)E.1T[a][d]=b;K d?E.1T[a][d]:a},35:J(c,b){c=c==1e?5b:c;L a=c[F];7(b){7(E.1T[a]){2V E.1T[a][b];b="";Q(b 1p E.1T[a])1Q;7(!b)E.35(c)}}N{1S{2V c[F]}1X(e){7(c.52)c.52(F)}2V E.1T[a]}},R:J(c,a,b){7(b){7(c.M==10){Q(L d 1p c)7(a.1i(c[d],b)===S)1Q}N Q(L i=0,M=c.M;i<M;i++)7(a.1i(c[i],b)===S)1Q}N{7(c.M==10){Q(L d 1p c)7(a.1P(c[d],d,c[d])===S)1Q}N Q(L i=0,M=c.M,1A=c[0];i<M&&a.1P(1A,i,1A)!==S;1A=c[++i]){}}K c},1l:J(b,a,c,i,d){7(E.1q(a))a=a.1P(b,i);K a&&a.1k==51&&c=="2o"&&!H.17(d)?a+"2S":a},1t:{1b:J(c,b){E.R((b||"").23(/\\s+/),J(i,a){7(c.15==1&&!E.1t.3Y(c.1t,a))c.1t+=(c.1t?" ":"")+a})},1V:J(c,b){7(c.15==1)c.1t=b!=10?E.3y(c.1t.23(/\\s+/),J(a){K!E.1t.3Y(b,a)}).6a(" "):""},3Y:J(b,a){K E.33(a,(b.1t||b).3X().23(/\\s+/))>-1}},68:J(b,c,a){L e={};Q(L d 1p c){e[d]=b.W[d];b.W[d]=c[d]}a.1P(b);Q(L d 1p c)b.W[d]=e[d]},1j:J(d,e,c){7(e=="27"||e=="1R"){L b,46={43:"4W",4U:"1Z",19:"3D"},3c=e=="27"?["7O","7M"]:["7J","7I"];J 5E(){b=e=="27"?d.7H:d.7F;L a=0,2N=0;E.R(3c,J(){a+=2M(E.2o(d,"7E"+6,P))||0;2N+=2M(E.2o(d,"2N"+6+"5X",P))||0});b-=24.7C(a+2N)}7(E(d).3H(":4d"))5E();N E.68(d,46,5E);K 24.2f(0,b)}K E.2o(d,e,c)},2o:J(e,k,j){L d;J 3x(b){7(!E.14.2d)K S;L a=T.4c.4K(b,V);K!a||a.4M("3x")==""}7(k=="1w"&&E.14.1d){d=E.1J(e.W,"1w");K d==""?"1":d}7(E.14.2z&&k=="19"){L c=e.W.50;e.W.50="0 7r 7o";e.W.50=c}7(k.1D(/4g/i))k=y;7(!j&&e.W&&e.W[k])d=e.W[k];N 7(T.4c&&T.4c.4K){7(k.1D(/4g/i))k="4g";k=k.1r(/([A-Z])/g,"-$1").2h();L h=T.4c.4K(e,V);7(h&&!3x(e))d=h.4M(k);N{L f=[],2C=[];Q(L a=e;a&&3x(a);a=a.1a)2C.4J(a);Q(L i=0;i<2C.M;i++)7(3x(2C[i])){f[i]=2C[i].W.19;2C[i].W.19="3D"}d=k=="19"&&f[2C.M-1]!=V?"2H":(h&&h.4M(k))||"";Q(L i=0;i<f.M;i++)7(f[i]!=V)2C[i].W.19=f[i]}7(k=="1w"&&d=="")d="1"}N 7(e.4n){L g=k.1r(/\\-(\\w)/g,J(a,b){K b.2E()});d=e.4n[k]||e.4n[g];7(!/^\\d+(2S)?$/i.17(d)&&/^\\d/.17(d)){L l=e.W.26,3K=e.3K.26;e.3K.26=e.4n.26;e.W.26=d||0;d=e.W.7f+"2S";e.W.26=l;e.3K.26=3K}}K d},4a:J(l,h){L k=[];h=h||T;7(1o h.3s==\'10\')h=h.2i||h[0]&&h[0].2i||T;E.R(l,J(i,d){7(!d)K;7(d.1k==51)d=d.3X();7(1o d=="25"){d=d.1r(/(<(\\w+)[^>]*?)\\/>/g,J(b,a,c){K c.1D(/^(aa|a6|7e|a5|4D|7a|a0|3m|9W|9U|9S)$/i)?b:a+"></"+c+">"});L f=E.3g(d).2h(),1x=h.3s("1x");L e=!f.1f("<9P")&&[1,"<2k 74=\'74\'>","</2k>"]||!f.1f("<9M")&&[1,"<73>","</73>"]||f.1D(/^<(9G|1U|9E|9B|9x)/)&&[1,"<1O>","</1O>"]||!f.1f("<4v")&&[2,"<1O><1U>","</1U></1O>"]||(!f.1f("<9w")||!f.1f("<9v"))&&[3,"<1O><1U><4v>","</4v></1U></1O>"]||!f.1f("<7e")&&[2,"<1O><1U></1U><6V>","</6V></1O>"]||E.14.1d&&[1,"1x<1x>","</1x>"]||[0,"",""];1x.3d=e[1]+d+e[2];2b(e[0]--)1x=1x.5o;7(E.14.1d){L g=!f.1f("<1O")&&f.1f("<1U")<0?1x.1C&&1x.1C.3p:e[1]=="<1O>"&&f.1f("<1U")<0?1x.3p:[];Q(L j=g.M-1;j>=0;--j)7(E.12(g[j],"1U")&&!g[j].3p.M)g[j].1a.34(g[j]);7(/^\\s/.17(d))1x.3o(h.5r(d.1D(/^\\s*/)[0]),1x.1C)}d=E.2I(1x.3p)}7(d.M===0&&(!E.12(d,"3u")&&!E.12(d,"2k")))K;7(d[0]==10||E.12(d,"3u")||d.11)k.1g(d);N k=E.37(k,d)});K k},1J:J(d,e,c){7(!d||d.15==3||d.15==8)K 10;L f=E.3E(d)?{}:E.46;7(e=="2p"&&E.14.2d)d.1a.3T;7(f[e]){7(c!=10)d[f[e]]=c;K d[f[e]]}N 7(E.14.1d&&e=="W")K E.1J(d.W,"9u",c);N 7(c==10&&E.14.1d&&E.12(d,"3u")&&(e=="9r"||e=="9o"))K d.9m(e).6K;N 7(d.28){7(c!=10){7(e=="U"&&E.12(d,"4D")&&d.1a)6Q"U 9i 9h\'t 9g 9e";d.9b(e,""+c)}7(E.14.1d&&/6O|3Q/.17(e)&&!E.3E(d))K d.4z(e,2);K d.4z(e)}N{7(e=="1w"&&E.14.1d){7(c!=10){d.6k=1;d.1E=(d.1E||"").1r(/6M\\([^)]*\\)/,"")+(2M(c).3X()=="96"?"":"6M(1w="+c*6L+")")}K d.1E&&d.1E.1f("1w=")>=0?(2M(d.1E.1D(/1w=([^)]*)/)[1])/6L).3X():""}e=e.1r(/-([a-z])/95,J(a,b){K b.2E()});7(c!=10)d[e]=c;K d[e]}},3g:J(a){K(a||"").1r(/^\\s+|\\s+$/g,"")},2I:J(b){L a=[];7(1o b!="93")Q(L i=0,M=b.M;i<M;i++)a.1g(b[i]);N a=b.2K(0);K a},33:J(b,a){Q(L i=0,M=a.M;i<M;i++)7(a[i]==b)K i;K-1},37:J(a,b){7(E.14.1d){Q(L i=0;b[i];i++)7(b[i].15!=8)a.1g(b[i])}N Q(L i=0;b[i];i++)a.1g(b[i]);K a},57:J(a){L c=[],2r={};1S{Q(L i=0,M=a.M;i<M;i++){L b=E.O(a[i]);7(!2r[b]){2r[b]=P;c.1g(a[i])}}}1X(e){c=a}K c},3y:J(c,a,d){L b=[];Q(L i=0,M=c.M;i<M;i++)7(!d&&a(c[i],i)||d&&!a(c[i],i))b.1g(c[i]);K b},2c:J(d,a){L c=[];Q(L i=0,M=d.M;i<M;i++){L b=a(d[i],i);7(b!==V&&b!=10){7(b.1k!=1M)b=[b];c=c.71(b)}}K c}});L v=8Y.8W.2h();E.14={5K:(v.1D(/.+(?:8T|8S|8R|8O)[\\/: ]([\\d.]+)/)||[])[1],2d:/77/.17(v),2z:/2z/.17(v),1d:/1d/.17(v)&&!/2z/.17(v),48:/48/.17(v)&&!/(8L|77)/.17(v)};L y=E.14.1d?"6H":"75";E.1s({8I:!E.14.1d||T.6F=="79",46:{"Q":"8F","8E":"1t","4g":y,75:y,6H:y,3d:"3d",1t:"1t",1A:"1A",2Y:"2Y",3k:"3k",8C:"8B",2p:"2p",8A:"8z",3T:"3T",6C:"6C",28:"28",12:"12"}});E.R({6B:J(a){K a.1a},8y:J(a){K E.4u(a,"1a")},8x:J(a){K E.2Z(a,2,"2B")},8v:J(a){K E.2Z(a,2,"4t")},8u:J(a){K E.4u(a,"2B")},8t:J(a){K E.4u(a,"4t")},8s:J(a){K E.5i(a.1a.1C,a)},8r:J(a){K E.5i(a.1C)},6z:J(a){K E.12(a,"8q")?a.8o||a.8n.T:E.2I(a.3p)}},J(c,d){E.1n[c]=J(b){L a=E.2c(6,d);7(b&&1o b=="25")a=E.3e(b,a);K 6.2F(E.57(a))}});E.R({6y:"3t",8m:"6q",3o:"6o",8l:"5a",8k:"6S"},J(c,b){E.1n[c]=J(){L a=18;K 6.R(J(){Q(L i=0,M=a.M;i<M;i++)E(a[i])[b](6)})}});E.R({8j:J(a){E.1J(6,a,"");7(6.15==1)6.52(a)},8i:J(a){E.1t.1b(6,a)},8h:J(a){E.1t.1V(6,a)},8g:J(a){E.1t[E.1t.3Y(6,a)?"1V":"1b"](6,a)},1V:J(a){7(!a||E.1E(a,[6]).r.M){E("*",6).1b(6).R(J(){E.16.1V(6);E.35(6)});7(6.1a)6.1a.34(6)}},4x:J(){E(">*",6).1V();2b(6.1C)6.34(6.1C)}},J(a,b){E.1n[a]=J(){K 6.R(b,18)}});E.R(["8f","5X"],J(i,c){L b=c.2h();E.1n[b]=J(a){K 6[0]==1e?E.14.2z&&T.1h["5e"+c]||E.14.2d&&1e["8e"+c]||T.6F=="79"&&T.1F["5e"+c]||T.1h["5e"+c]:6[0]==T?24.2f(24.2f(T.1h["5d"+c],T.1F["5d"+c]),24.2f(T.1h["5L"+c],T.1F["5L"+c])):a==10?(6.M?E.1j(6[0],b):V):6.1j(b,a.1k==4e?a:a+"2S")}});L C=E.14.2d&&4s(E.14.5K)<8c?"(?:[\\\\w*4r-]|\\\\\\\\.)":"(?:[\\\\w\\8b-\\8a*4r-]|\\\\\\\\.)",6v=1B 4q("^>\\\\s*("+C+"+)"),6u=1B 4q("^("+C+"+)(#)("+C+"+)"),6s=1B 4q("^([#.]?)("+C+"*)");E.1s({6r:{"":J(a,i,m){K m[2]=="*"||E.12(a,m[2])},"#":J(a,i,m){K a.4z("2w")==m[2]},":":{89:J(a,i,m){K i<m[3]-0},88:J(a,i,m){K i>m[3]-0},2Z:J(a,i,m){K m[3]-0==i},6Z:J(a,i,m){K m[3]-0==i},3j:J(a,i){K i==0},3J:J(a,i,m,r){K i==r.M-1},6n:J(a,i){K i%2==0},6l:J(a,i){K i%2},"3j-4p":J(a){K a.1a.3S("*")[0]==a},"3J-4p":J(a){K E.2Z(a.1a.5o,1,"4t")==a},"83-4p":J(a){K!E.2Z(a.1a.5o,2,"4t")},6B:J(a){K a.1C},4x:J(a){K!a.1C},82:J(a,i,m){K(a.6x||a.81||E(a).1u()||"").1f(m[3])>=0},4d:J(a){K"1Z"!=a.U&&E.1j(a,"19")!="2H"&&E.1j(a,"4U")!="1Z"},1Z:J(a){K"1Z"==a.U||E.1j(a,"19")=="2H"||E.1j(a,"4U")=="1Z"},80:J(a){K!a.2Y},2Y:J(a){K a.2Y},3k:J(a){K a.3k},2p:J(a){K a.2p||E.1J(a,"2p")},1u:J(a){K"1u"==a.U},5u:J(a){K"5u"==a.U},5t:J(a){K"5t"==a.U},59:J(a){K"59"==a.U},3I:J(a){K"3I"==a.U},58:J(a){K"58"==a.U},6j:J(a){K"6j"==a.U},6i:J(a){K"6i"==a.U},2G:J(a){K"2G"==a.U||E.12(a,"2G")},4D:J(a){K/4D|2k|6h|2G/i.17(a.12)},3Y:J(a,i,m){K E.2s(m[3],a).M},7X:J(a){K/h\\d/i.17(a.12)},7W:J(a){K E.3y(E.3G,J(b){K a==b.Y}).M}}},6g:[/^(\\[) *@?([\\w-]+) *([!*$^~=]*) *(\'?"?)(.*?)\\4 *\\]/,/^(:)([\\w-]+)\\("?\'?(.*?(\\(.*?\\))?[^(]*?)"?\'?\\)/,1B 4q("^([:.#]*)("+C+"+)")],3e:J(a,c,b){L d,2m=[];2b(a&&a!=d){d=a;L f=E.1E(a,c,b);a=f.t.1r(/^\\s*,\\s*/,"");2m=b?c=f.r:E.37(2m,f.r)}K 2m},2s:J(t,p){7(1o t!="25")K[t];7(p&&p.15!=1&&p.15!=9)K[];p=p||T;L d=[p],2r=[],3J,12;2b(t&&3J!=t){L r=[];3J=t;t=E.3g(t);L o=S;L g=6v;L m=g.2O(t);7(m){12=m[1].2E();Q(L i=0;d[i];i++)Q(L c=d[i].1C;c;c=c.2B)7(c.15==1&&(12=="*"||c.12.2E()==12))r.1g(c);d=r;t=t.1r(g,"");7(t.1f(" ")==0)6w;o=P}N{g=/^([>+~])\\s*(\\w*)/i;7((m=g.2O(t))!=V){r=[];L l={};12=m[2].2E();m=m[1];Q(L j=0,3f=d.M;j<3f;j++){L n=m=="~"||m=="+"?d[j].2B:d[j].1C;Q(;n;n=n.2B)7(n.15==1){L h=E.O(n);7(m=="~"&&l[h])1Q;7(!12||n.12.2E()==12){7(m=="~")l[h]=P;r.1g(n)}7(m=="+")1Q}}d=r;t=E.3g(t.1r(g,""));o=P}}7(t&&!o){7(!t.1f(",")){7(p==d[0])d.4l();2r=E.37(2r,d);r=d=[p];t=" "+t.6e(1,t.M)}N{L k=6u;L m=k.2O(t);7(m){m=[0,m[2],m[3],m[1]]}N{k=6s;m=k.2O(t)}m[2]=m[2].1r(/\\\\/g,"");L f=d[d.M-1];7(m[1]=="#"&&f&&f.5J&&!E.3E(f)){L q=f.5J(m[2]);7((E.14.1d||E.14.2z)&&q&&1o q.2w=="25"&&q.2w!=m[2])q=E(\'[@2w="\'+m[2]+\'"]\',f)[0];d=r=q&&(!m[3]||E.12(q,m[3]))?[q]:[]}N{Q(L i=0;d[i];i++){L a=m[1]=="#"&&m[3]?m[3]:m[1]!=""||m[0]==""?"*":m[2];7(a=="*"&&d[i].12.2h()=="3V")a="3m";r=E.37(r,d[i].3S(a))}7(m[1]==".")r=E.55(r,m[2]);7(m[1]=="#"){L e=[];Q(L i=0;r[i];i++)7(r[i].4z("2w")==m[2]){e=[r[i]];1Q}r=e}d=r}t=t.1r(k,"")}}7(t){L b=E.1E(t,r);d=r=b.r;t=E.3g(b.t)}}7(t)d=[];7(d&&p==d[0])d.4l();2r=E.37(2r,d);K 2r},55:J(r,m,a){m=" "+m+" ";L c=[];Q(L i=0;r[i];i++){L b=(" "+r[i].1t+" ").1f(m)>=0;7(!a&&b||a&&!b)c.1g(r[i])}K c},1E:J(t,r,h){L d;2b(t&&t!=d){d=t;L p=E.6g,m;Q(L i=0;p[i];i++){m=p[i].2O(t);7(m){t=t.7V(m[0].M);m[2]=m[2].1r(/\\\\/g,"");1Q}}7(!m)1Q;7(m[1]==":"&&m[2]=="56")r=G.17(m[3])?E.1E(m[3],r,P).r:E(r).56(m[3]);N 7(m[1]==".")r=E.55(r,m[2],h);N 7(m[1]=="["){L g=[],U=m[3];Q(L i=0,3f=r.M;i<3f;i++){L a=r[i],z=a[E.46[m[2]]||m[2]];7(z==V||/6O|3Q|2p/.17(m[2]))z=E.1J(a,m[2])||\'\';7((U==""&&!!z||U=="="&&z==m[5]||U=="!="&&z!=m[5]||U=="^="&&z&&!z.1f(m[5])||U=="$="&&z.6e(z.M-m[5].M)==m[5]||(U=="*="||U=="~=")&&z.1f(m[5])>=0)^h)g.1g(a)}r=g}N 7(m[1]==":"&&m[2]=="2Z-4p"){L e={},g=[],17=/(-?)(\\d*)n((?:\\+|-)?\\d*)/.2O(m[3]=="6n"&&"2n"||m[3]=="6l"&&"2n+1"||!/\\D/.17(m[3])&&"7U+"+m[3]||m[3]),3j=(17[1]+(17[2]||1))-0,d=17[3]-0;Q(L i=0,3f=r.M;i<3f;i++){L j=r[i],1a=j.1a,2w=E.O(1a);7(!e[2w]){L c=1;Q(L n=1a.1C;n;n=n.2B)7(n.15==1)n.4k=c++;e[2w]=P}L b=S;7(3j==0){7(j.4k==d)b=P}N 7((j.4k-d)%3j==0&&(j.4k-d)/3j>=0)b=P;7(b^h)g.1g(j)}r=g}N{L f=E.6r[m[1]];7(1o f=="3V")f=f[m[2]];7(1o f=="25")f=6c("S||J(a,i){K "+f+";}");r=E.3y(r,J(a,i){K f(a,i,m,r)},h)}}K{r:r,t:t}},4u:J(b,c){L d=[];L a=b[c];2b(a&&a!=T){7(a.15==1)d.1g(a);a=a[c]}K d},2Z:J(a,e,c,b){e=e||1;L d=0;Q(;a;a=a[c])7(a.15==1&&++d==e)1Q;K a},5i:J(n,a){L r=[];Q(;n;n=n.2B){7(n.15==1&&(!a||n!=a))r.1g(n)}K r}});E.16={1b:J(f,i,g,e){7(f.15==3||f.15==8)K;7(E.14.1d&&f.53!=10)f=1e;7(!g.2D)g.2D=6.2D++;7(e!=10){L h=g;g=J(){K h.1i(6,18)};g.O=e;g.2D=h.2D}L j=E.O(f,"2R")||E.O(f,"2R",{}),1v=E.O(f,"1v")||E.O(f,"1v",J(){L a;7(1o E=="10"||E.16.5f)K a;a=E.16.1v.1i(18.3R.Y,18);K a});1v.Y=f;E.R(i.23(/\\s+/),J(c,b){L a=b.23(".");b=a[0];g.U=a[1];L d=j[b];7(!d){d=j[b]={};7(!E.16.2y[b]||E.16.2y[b].4j.1P(f)===S){7(f.3F)f.3F(b,1v,S);N 7(f.6b)f.6b("4i"+b,1v)}}d[g.2D]=g;E.16.2a[b]=P});f=V},2D:1,2a:{},1V:J(e,h,f){7(e.15==3||e.15==8)K;L i=E.O(e,"2R"),29,4X;7(i){7(h==10||(1o h=="25"&&h.7T(0)=="."))Q(L g 1p i)6.1V(e,g+(h||""));N{7(h.U){f=h.2q;h=h.U}E.R(h.23(/\\s+/),J(b,a){L c=a.23(".");a=c[0];7(i[a]){7(f)2V i[a][f.2D];N Q(f 1p i[a])7(!c[1]||i[a][f].U==c[1])2V i[a][f];Q(29 1p i[a])1Q;7(!29){7(!E.16.2y[a]||E.16.2y[a].4h.1P(e)===S){7(e.67)e.67(a,E.O(e,"1v"),S);N 7(e.66)e.66("4i"+a,E.O(e,"1v"))}29=V;2V i[a]}}})}Q(29 1p i)1Q;7(!29){L d=E.O(e,"1v");7(d)d.Y=V;E.35(e,"2R");E.35(e,"1v")}}},1N:J(g,c,d,f,h){c=E.2I(c||[]);7(g.1f("!")>=0){g=g.2K(0,-1);L a=P}7(!d){7(6.2a[g])E("*").1b([1e,T]).1N(g,c)}N{7(d.15==3||d.15==8)K 10;L b,29,1n=E.1q(d[g]||V),16=!c[0]||!c[0].36;7(16)c.4J(6.4Z({U:g,2L:d}));c[0].U=g;7(a)c[0].65=P;7(E.1q(E.O(d,"1v")))b=E.O(d,"1v").1i(d,c);7(!1n&&d["4i"+g]&&d["4i"+g].1i(d,c)===S)b=S;7(16)c.4l();7(h&&E.1q(h)){29=h.1i(d,b==V?c:c.71(b));7(29!==10)b=29}7(1n&&f!==S&&b!==S&&!(E.12(d,\'a\')&&g=="4V")){6.5f=P;1S{d[g]()}1X(e){}}6.5f=S}K b},1v:J(c){L a;c=E.16.4Z(c||1e.16||{});L b=c.U.23(".");c.U=b[0];L f=E.O(6,"2R")&&E.O(6,"2R")[c.U],42=1M.2l.2K.1P(18,1);42.4J(c);Q(L j 1p f){L d=f[j];42[0].2q=d;42[0].O=d.O;7(!b[1]&&!c.65||d.U==b[1]){L e=d.1i(6,42);7(a!==S)a=e;7(e===S){c.36();c.44()}}}7(E.14.1d)c.2L=c.36=c.44=c.2q=c.O=V;K a},4Z:J(c){L a=c;c=E.1s({},a);c.36=J(){7(a.36)a.36();a.7S=S};c.44=J(){7(a.44)a.44();a.7R=P};7(!c.2L)c.2L=c.7Q||T;7(c.2L.15==3)c.2L=a.2L.1a;7(!c.4S&&c.5w)c.4S=c.5w==c.2L?c.7P:c.5w;7(c.64==V&&c.63!=V){L b=T.1F,1h=T.1h;c.64=c.63+(b&&b.2v||1h&&1h.2v||0)-(b.62||0);c.7N=c.7L+(b&&b.2x||1h&&1h.2x||0)-(b.60||0)}7(!c.3c&&((c.4f||c.4f===0)?c.4f:c.5Z))c.3c=c.4f||c.5Z;7(!c.7b&&c.5Y)c.7b=c.5Y;7(!c.3c&&c.2G)c.3c=(c.2G&1?1:(c.2G&2?3:(c.2G&4?2:0)));K c},2y:{21:{4j:J(){5M();K},4h:J(){K}},3C:{4j:J(){7(E.14.1d)K S;E(6).2j("4P",E.16.2y.3C.2q);K P},4h:J(){7(E.14.1d)K S;E(6).3w("4P",E.16.2y.3C.2q);K P},2q:J(a){7(I(a,6))K P;18[0].U="3C";K E.16.1v.1i(6,18)}},3B:{4j:J(){7(E.14.1d)K S;E(6).2j("4O",E.16.2y.3B.2q);K P},4h:J(){7(E.14.1d)K S;E(6).3w("4O",E.16.2y.3B.2q);K P},2q:J(a){7(I(a,6))K P;18[0].U="3B";K E.16.1v.1i(6,18)}}}};E.1n.1s({2j:J(c,a,b){K c=="4H"?6.2X(c,a,b):6.R(J(){E.16.1b(6,c,b||a,b&&a)})},2X:J(d,b,c){K 6.R(J(){E.16.1b(6,d,J(a){E(6).3w(a);K(c||b).1i(6,18)},c&&b)})},3w:J(a,b){K 6.R(J(){E.16.1V(6,a,b)})},1N:J(c,a,b){K 6.R(J(){E.16.1N(c,a,6,P,b)})},5n:J(c,a,b){7(6[0])K E.16.1N(c,a,6[0],S,b);K 10},2g:J(){L b=18;K 6.4V(J(a){6.4N=0==6.4N?1:0;a.36();K b[6.4N].1i(6,18)||S})},7D:J(a,b){K 6.2j(\'3C\',a).2j(\'3B\',b)},21:J(a){5M();7(E.2Q)a.1P(T,E);N E.3A.1g(J(){K a.1P(6,E)});K 6}});E.1s({2Q:S,3A:[],21:J(){7(!E.2Q){E.2Q=P;7(E.3A){E.R(E.3A,J(){6.1i(T)});E.3A=V}E(T).5n("21")}}});L x=S;J 5M(){7(x)K;x=P;7(T.3F&&!E.14.2z)T.3F("5W",E.21,S);7(E.14.1d&&1e==3b)(J(){7(E.2Q)K;1S{T.1F.7B("26")}1X(3a){3z(18.3R,0);K}E.21()})();7(E.14.2z)T.3F("5W",J(){7(E.2Q)K;Q(L i=0;i<T.4L.M;i++)7(T.4L[i].2Y){3z(18.3R,0);K}E.21()},S);7(E.14.2d){L a;(J(){7(E.2Q)K;7(T.39!="5V"&&T.39!="1y"){3z(18.3R,0);K}7(a===10)a=E("W, 7a[7A=7z]").M;7(T.4L.M!=a){3z(18.3R,0);K}E.21()})()}E.16.1b(1e,"3U",E.21)}E.R(("7y,7x,3U,7w,5d,4H,4V,7v,"+"7G,7u,7t,4P,4O,7s,2k,"+"58,7K,7q,7p,3a").23(","),J(i,b){E.1n[b]=J(a){K a?6.2j(b,a):6.1N(b)}});L I=J(a,c){L b=a.4S;2b(b&&b!=c)1S{b=b.1a}1X(3a){b=c}K b==c};E(1e).2j("4H",J(){E("*").1b(T).3w()});E.1n.1s({3U:J(g,d,c){7(E.1q(g))K 6.2j("3U",g);L e=g.1f(" ");7(e>=0){L i=g.2K(e,g.M);g=g.2K(0,e)}c=c||J(){};L f="4Q";7(d)7(E.1q(d)){c=d;d=V}N{d=E.3m(d);f="61"}L h=6;E.3P({1c:g,U:f,1H:"3q",O:d,1y:J(a,b){7(b=="1W"||b=="5U")h.3q(i?E("<1x/>").3t(a.4b.1r(/<1m(.|\\s)*?\\/1m>/g,"")).2s(i):a.4b);h.R(c,[a.4b,b,a])}});K 6},7n:J(){K E.3m(6.5T())},5T:J(){K 6.2c(J(){K E.12(6,"3u")?E.2I(6.7m):6}).1E(J(){K 6.31&&!6.2Y&&(6.3k||/2k|6h/i.17(6.12)||/1u|1Z|3I/i.17(6.U))}).2c(J(i,c){L b=E(6).5O();K b==V?V:b.1k==1M?E.2c(b,J(a,i){K{31:c.31,1A:a}}):{31:c.31,1A:b}}).22()}});E.R("5S,6d,5R,6D,5Q,6m".23(","),J(i,o){E.1n[o]=J(f){K 6.2j(o,f)}});L B=(1B 3v).3L();E.1s({22:J(d,b,a,c){7(E.1q(b)){a=b;b=V}K E.3P({U:"4Q",1c:d,O:b,1W:a,1H:c})},7l:J(b,a){K E.22(b,V,a,"1m")},7k:J(c,b,a){K E.22(c,b,a,"3i")},7i:J(d,b,a,c){7(E.1q(b)){a=b;b={}}K E.3P({U:"61",1c:d,O:b,1W:a,1H:c})},85:J(a){E.1s(E.4I,a)},4I:{2a:P,U:"4Q",2U:0,5P:"4o/x-7h-3u-7g",5N:P,3l:P,O:V,6p:V,3I:V,49:{3M:"4o/3M, 1u/3M",3q:"1u/3q",1m:"1u/4m, 4o/4m",3i:"4o/3i, 1u/4m",1u:"1u/a7",4G:"*/*"}},4F:{},3P:J(s){L f,2W=/=\\?(&|$)/g,1z,O;s=E.1s(P,s,E.1s(P,{},E.4I,s));7(s.O&&s.5N&&1o s.O!="25")s.O=E.3m(s.O);7(s.1H=="4E"){7(s.U.2h()=="22"){7(!s.1c.1D(2W))s.1c+=(s.1c.1D(/\\?/)?"&":"?")+(s.4E||"7d")+"=?"}N 7(!s.O||!s.O.1D(2W))s.O=(s.O?s.O+"&":"")+(s.4E||"7d")+"=?";s.1H="3i"}7(s.1H=="3i"&&(s.O&&s.O.1D(2W)||s.1c.1D(2W))){f="4E"+B++;7(s.O)s.O=(s.O+"").1r(2W,"="+f+"$1");s.1c=s.1c.1r(2W,"="+f+"$1");s.1H="1m";1e[f]=J(a){O=a;1W();1y();1e[f]=10;1S{2V 1e[f]}1X(e){}7(h)h.34(g)}}7(s.1H=="1m"&&s.1T==V)s.1T=S;7(s.1T===S&&s.U.2h()=="22"){L i=(1B 3v()).3L();L j=s.1c.1r(/(\\?|&)4r=.*?(&|$)/,"$a4="+i+"$2");s.1c=j+((j==s.1c)?(s.1c.1D(/\\?/)?"&":"?")+"4r="+i:"")}7(s.O&&s.U.2h()=="22"){s.1c+=(s.1c.1D(/\\?/)?"&":"?")+s.O;s.O=V}7(s.2a&&!E.5H++)E.16.1N("5S");7((!s.1c.1f("a3")||!s.1c.1f("//"))&&s.1H=="1m"&&s.U.2h()=="22"){L h=T.3S("6f")[0];L g=T.3s("1m");g.3Q=s.1c;7(s.7c)g.a2=s.7c;7(!f){L l=S;g.9Z=g.9Y=J(){7(!l&&(!6.39||6.39=="5V"||6.39=="1y")){l=P;1W();1y();h.34(g)}}}h.38(g);K 10}L m=S;L k=1e.78?1B 78("9X.9V"):1B 76();k.9T(s.U,s.1c,s.3l,s.6p,s.3I);1S{7(s.O)k.4C("9R-9Q",s.5P);7(s.5C)k.4C("9O-5A-9N",E.4F[s.1c]||"9L, 9K 9I 9H 5z:5z:5z 9F");k.4C("X-9C-9A","76");k.4C("9z",s.1H&&s.49[s.1H]?s.49[s.1H]+", */*":s.49.4G)}1X(e){}7(s.6Y)s.6Y(k);7(s.2a)E.16.1N("6m",[k,s]);L c=J(a){7(!m&&k&&(k.39==4||a=="2U")){m=P;7(d){6I(d);d=V}1z=a=="2U"&&"2U"||!E.6X(k)&&"3a"||s.5C&&E.6J(k,s.1c)&&"5U"||"1W";7(1z=="1W"){1S{O=E.6W(k,s.1H)}1X(e){1z="5x"}}7(1z=="1W"){L b;1S{b=k.5q("6U-5A")}1X(e){}7(s.5C&&b)E.4F[s.1c]=b;7(!f)1W()}N E.5v(s,k,1z);1y();7(s.3l)k=V}};7(s.3l){L d=53(c,13);7(s.2U>0)3z(J(){7(k){k.9t();7(!m)c("2U")}},s.2U)}1S{k.9s(s.O)}1X(e){E.5v(s,k,V,e)}7(!s.3l)c();J 1W(){7(s.1W)s.1W(O,1z);7(s.2a)E.16.1N("5Q",[k,s])}J 1y(){7(s.1y)s.1y(k,1z);7(s.2a)E.16.1N("5R",[k,s]);7(s.2a&&!--E.5H)E.16.1N("6d")}K k},5v:J(s,a,b,e){7(s.3a)s.3a(a,b,e);7(s.2a)E.16.1N("6D",[a,s,e])},5H:0,6X:J(r){1S{K!r.1z&&9q.9p=="59:"||(r.1z>=6T&&r.1z<9n)||r.1z==6R||r.1z==9l||E.14.2d&&r.1z==10}1X(e){}K S},6J:J(a,c){1S{L b=a.5q("6U-5A");K a.1z==6R||b==E.4F[c]||E.14.2d&&a.1z==10}1X(e){}K S},6W:J(r,b){L c=r.5q("9k-U");L d=b=="3M"||!b&&c&&c.1f("3M")>=0;L a=d?r.9j:r.4b;7(d&&a.1F.28=="5x")6Q"5x";7(b=="1m")E.5g(a);7(b=="3i")a=6c("("+a+")");K a},3m:J(a){L s=[];7(a.1k==1M||a.5h)E.R(a,J(){s.1g(3r(6.31)+"="+3r(6.1A))});N Q(L j 1p a)7(a[j]&&a[j].1k==1M)E.R(a[j],J(){s.1g(3r(j)+"="+3r(6))});N s.1g(3r(j)+"="+3r(a[j]));K s.6a("&").1r(/%20/g,"+")}});E.1n.1s({1G:J(c,b){K c?6.2e({1R:"1G",27:"1G",1w:"1G"},c,b):6.1E(":1Z").R(J(){6.W.19=6.5s||"";7(E.1j(6,"19")=="2H"){L a=E("<"+6.28+" />").6y("1h");6.W.19=a.1j("19");7(6.W.19=="2H")6.W.19="3D";a.1V()}}).3h()},1I:J(b,a){K b?6.2e({1R:"1I",27:"1I",1w:"1I"},b,a):6.1E(":4d").R(J(){6.5s=6.5s||E.1j(6,"19");6.W.19="2H"}).3h()},6N:E.1n.2g,2g:J(a,b){K E.1q(a)&&E.1q(b)?6.6N(a,b):a?6.2e({1R:"2g",27:"2g",1w:"2g"},a,b):6.R(J(){E(6)[E(6).3H(":1Z")?"1G":"1I"]()})},9f:J(b,a){K 6.2e({1R:"1G"},b,a)},9d:J(b,a){K 6.2e({1R:"1I"},b,a)},9c:J(b,a){K 6.2e({1R:"2g"},b,a)},9a:J(b,a){K 6.2e({1w:"1G"},b,a)},99:J(b,a){K 6.2e({1w:"1I"},b,a)},97:J(c,a,b){K 6.2e({1w:a},c,b)},2e:J(l,k,j,h){L i=E.6P(k,j,h);K 6[i.2P===S?"R":"2P"](J(){7(6.15!=1)K S;L g=E.1s({},i);L f=E(6).3H(":1Z"),4A=6;Q(L p 1p l){7(l[p]=="1I"&&f||l[p]=="1G"&&!f)K E.1q(g.1y)&&g.1y.1i(6);7(p=="1R"||p=="27"){g.19=E.1j(6,"19");g.32=6.W.32}}7(g.32!=V)6.W.32="1Z";g.40=E.1s({},l);E.R(l,J(c,a){L e=1B E.2t(4A,g,c);7(/2g|1G|1I/.17(a))e[a=="2g"?f?"1G":"1I":a](l);N{L b=a.3X().1D(/^([+-]=)?([\\d+-.]+)(.*)$/),1Y=e.2m(P)||0;7(b){L d=2M(b[2]),2A=b[3]||"2S";7(2A!="2S"){4A.W[c]=(d||1)+2A;1Y=((d||1)/e.2m(P))*1Y;4A.W[c]=1Y+2A}7(b[1])d=((b[1]=="-="?-1:1)*d)+1Y;e.45(1Y,d,2A)}N e.45(1Y,a,"")}});K P})},2P:J(a,b){7(E.1q(a)||(a&&a.1k==1M)){b=a;a="2t"}7(!a||(1o a=="25"&&!b))K A(6[0],a);K 6.R(J(){7(b.1k==1M)A(6,a,b);N{A(6,a).1g(b);7(A(6,a).M==1)b.1i(6)}})},94:J(b,c){L a=E.3G;7(b)6.2P([]);6.R(J(){Q(L i=a.M-1;i>=0;i--)7(a[i].Y==6){7(c)a[i](P);a.72(i,1)}});7(!c)6.5p();K 6}});L A=J(b,c,a){7(!b)K 10;c=c||"2t";L q=E.O(b,c+"2P");7(!q||a)q=E.O(b,c+"2P",a?E.2I(a):[]);K q};E.1n.5p=J(a){a=a||"2t";K 6.R(J(){L q=A(6,a);q.4l();7(q.M)q[0].1i(6)})};E.1s({6P:J(b,a,c){L d=b&&b.1k==92?b:{1y:c||!c&&a||E.1q(b)&&b,2u:b,3Z:c&&a||a&&a.1k!=91&&a};d.2u=(d.2u&&d.2u.1k==51?d.2u:{90:8Z,9D:6T}[d.2u])||8X;d.5y=d.1y;d.1y=J(){7(d.2P!==S)E(6).5p();7(E.1q(d.5y))d.5y.1i(6)};K d},3Z:{70:J(p,n,b,a){K b+a*p},5j:J(p,n,b,a){K((-24.8V(p*24.8U)/2)+0.5)*a+b}},3G:[],3W:V,2t:J(b,c,a){6.11=c;6.Y=b;6.1l=a;7(!c.47)c.47={}}});E.2t.2l={4y:J(){7(6.11.30)6.11.30.1i(6.Y,[6.2J,6]);(E.2t.30[6.1l]||E.2t.30.4G)(6);7(6.1l=="1R"||6.1l=="27")6.Y.W.19="3D"},2m:J(a){7(6.Y[6.1l]!=V&&6.Y.W[6.1l]==V)K 6.Y[6.1l];L r=2M(E.1j(6.Y,6.1l,a));K r&&r>-8Q?r:2M(E.2o(6.Y,6.1l))||0},45:J(c,b,d){6.5B=(1B 3v()).3L();6.1Y=c;6.3h=b;6.2A=d||6.2A||"2S";6.2J=6.1Y;6.4B=6.4w=0;6.4y();L e=6;J t(a){K e.30(a)}t.Y=6.Y;E.3G.1g(t);7(E.3W==V){E.3W=53(J(){L a=E.3G;Q(L i=0;i<a.M;i++)7(!a[i]())a.72(i--,1);7(!a.M){6I(E.3W);E.3W=V}},13)}},1G:J(){6.11.47[6.1l]=E.1J(6.Y.W,6.1l);6.11.1G=P;6.45(0,6.2m());7(6.1l=="27"||6.1l=="1R")6.Y.W[6.1l]="8N";E(6.Y).1G()},1I:J(){6.11.47[6.1l]=E.1J(6.Y.W,6.1l);6.11.1I=P;6.45(6.2m(),0)},30:J(a){L t=(1B 3v()).3L();7(a||t>6.11.2u+6.5B){6.2J=6.3h;6.4B=6.4w=1;6.4y();6.11.40[6.1l]=P;L b=P;Q(L i 1p 6.11.40)7(6.11.40[i]!==P)b=S;7(b){7(6.11.19!=V){6.Y.W.32=6.11.32;6.Y.W.19=6.11.19;7(E.1j(6.Y,"19")=="2H")6.Y.W.19="3D"}7(6.11.1I)6.Y.W.19="2H";7(6.11.1I||6.11.1G)Q(L p 1p 6.11.40)E.1J(6.Y.W,p,6.11.47[p])}7(b&&E.1q(6.11.1y))6.11.1y.1i(6.Y);K S}N{L n=t-6.5B;6.4w=n/6.11.2u;6.4B=E.3Z[6.11.3Z||(E.3Z.5j?"5j":"70")](6.4w,n,0,1,6.11.2u);6.2J=6.1Y+((6.3h-6.1Y)*6.4B);6.4y()}K P}};E.2t.30={2v:J(a){a.Y.2v=a.2J},2x:J(a){a.Y.2x=a.2J},1w:J(a){E.1J(a.Y.W,"1w",a.2J)},4G:J(a){a.Y.W[a.1l]=a.2J+a.2A}};E.1n.5L=J(){L b=0,3b=0,Y=6[0],5l;7(Y)8M(E.14){L d=Y.1a,41=Y,1K=Y.1K,1L=Y.2i,5D=2d&&4s(5K)<8J&&!/a1/i.17(v),2T=E.1j(Y,"43")=="2T";7(Y.6G){L c=Y.6G();1b(c.26+24.2f(1L.1F.2v,1L.1h.2v),c.3b+24.2f(1L.1F.2x,1L.1h.2x));1b(-1L.1F.62,-1L.1F.60)}N{1b(Y.5G,Y.5F);2b(1K){1b(1K.5G,1K.5F);7(48&&!/^t(8H|d|h)$/i.17(1K.28)||2d&&!5D)2N(1K);7(!2T&&E.1j(1K,"43")=="2T")2T=P;41=/^1h$/i.17(1K.28)?41:1K;1K=1K.1K}2b(d&&d.28&&!/^1h|3q$/i.17(d.28)){7(!/^8G|1O.*$/i.17(E.1j(d,"19")))1b(-d.2v,-d.2x);7(48&&E.1j(d,"32")!="4d")2N(d);d=d.1a}7((5D&&(2T||E.1j(41,"43")=="4W"))||(48&&E.1j(41,"43")!="4W"))1b(-1L.1h.5G,-1L.1h.5F);7(2T)1b(24.2f(1L.1F.2v,1L.1h.2v),24.2f(1L.1F.2x,1L.1h.2x))}5l={3b:3b,26:b}}J 2N(a){1b(E.2o(a,"a8",P),E.2o(a,"a9",P))}J 1b(l,t){b+=4s(l)||0;3b+=4s(t)||0}K 5l}})();',62,631,'||||||this|if||||||||||||||||||||||||||||||||||||||function|return|var|length|else|data|true|for|each|false|document|type|null|style||elem||undefined|options|nodeName||browser|nodeType|event|test|arguments|display|parentNode|add|url|msie|window|indexOf|push|body|apply|css|constructor|prop|script|fn|typeof|in|isFunction|replace|extend|className|text|handle|opacity|div|complete|status|value|new|firstChild|match|filter|documentElement|show|dataType|hide|attr|offsetParent|doc|Array|trigger|table|call|break|height|try|cache|tbody|remove|success|catch|start|hidden||ready|get|split|Math|string|left|width|tagName|ret|global|while|map|safari|animate|max|toggle|toLowerCase|ownerDocument|bind|select|prototype|cur||curCSS|selected|handler|done|find|fx|duration|scrollLeft|id|scrollTop|special|opera|unit|nextSibling|stack|guid|toUpperCase|pushStack|button|none|makeArray|now|slice|target|parseFloat|border|exec|queue|isReady|events|px|fixed|timeout|delete|jsre|one|disabled|nth|step|name|overflow|inArray|removeChild|removeData|preventDefault|merge|appendChild|readyState|error|top|which|innerHTML|multiFilter|rl|trim|end|json|first|checked|async|param|elems|insertBefore|childNodes|html|encodeURIComponent|createElement|append|form|Date|unbind|color|grep|setTimeout|readyList|mouseleave|mouseenter|block|isXMLDoc|addEventListener|timers|is|password|last|runtimeStyle|getTime|xml|jQuery|domManip|ajax|src|callee|getElementsByTagName|selectedIndex|load|object|timerId|toString|has|easing|curAnim|offsetChild|args|position|stopPropagation|custom|props|orig|mozilla|accepts|clean|responseText|defaultView|visible|String|charCode|float|teardown|on|setup|nodeIndex|shift|javascript|currentStyle|application|child|RegExp|_|parseInt|previousSibling|dir|tr|state|empty|update|getAttribute|self|pos|setRequestHeader|input|jsonp|lastModified|_default|unload|ajaxSettings|unshift|getComputedStyle|styleSheets|getPropertyValue|lastToggle|mouseout|mouseover|GET|andSelf|relatedTarget|init|visibility|click|absolute|index|container|fix|outline|Number|removeAttribute|setInterval|prevObject|classFilter|not|unique|submit|file|after|windowData|deep|scroll|client|triggered|globalEval|jquery|sibling|swing|clone|results|wrapAll|triggerHandler|lastChild|dequeue|getResponseHeader|createTextNode|oldblock|checkbox|radio|handleError|fromElement|parsererror|old|00|Modified|startTime|ifModified|safari2|getWH|offsetTop|offsetLeft|active|values|getElementById|version|offset|bindReady|processData|val|contentType|ajaxSuccess|ajaxComplete|ajaxStart|serializeArray|notmodified|loaded|DOMContentLoaded|Width|ctrlKey|keyCode|clientTop|POST|clientLeft|clientX|pageX|exclusive|detachEvent|removeEventListener|swap|cloneNode|join|attachEvent|eval|ajaxStop|substr|head|parse|textarea|reset|image|zoom|odd|ajaxSend|even|before|username|prepend|expr|quickClass|uuid|quickID|quickChild|continue|textContent|appendTo|contents|evalScript|parent|defaultValue|ajaxError|setArray|compatMode|getBoundingClientRect|styleFloat|clearInterval|httpNotModified|nodeValue|100|alpha|_toggle|href|speed|throw|304|replaceWith|200|Last|colgroup|httpData|httpSuccess|beforeSend|eq|linear|concat|splice|fieldset|multiple|cssFloat|XMLHttpRequest|webkit|ActiveXObject|CSS1Compat|link|metaKey|scriptCharset|callback|col|pixelLeft|urlencoded|www|post|hasClass|getJSON|getScript|elements|serialize|black|keyup|keypress|solid|change|mousemove|mouseup|dblclick|resize|focus|blur|stylesheet|rel|doScroll|round|hover|padding|offsetHeight|mousedown|offsetWidth|Bottom|Top|keydown|clientY|Right|pageY|Left|toElement|srcElement|cancelBubble|returnValue|charAt|0n|substring|animated|header|noConflict|line|enabled|innerText|contains|only|weight|ajaxSetup|font|size|gt|lt|uFFFF|u0128|417|Boolean|inner|Height|toggleClass|removeClass|addClass|removeAttr|replaceAll|insertAfter|prependTo|contentWindow|contentDocument|wrap|iframe|children|siblings|prevAll|nextAll|prev|wrapInner|next|parents|maxLength|maxlength|readOnly|readonly|reverse|class|htmlFor|inline|able|boxModel|522|setData|compatible|with|1px|ie|getData|10000|ra|it|rv|PI|cos|userAgent|400|navigator|600|slow|Function|Object|array|stop|ig|NaN|fadeTo|option|fadeOut|fadeIn|setAttribute|slideToggle|slideUp|changed|slideDown|be|can|property|responseXML|content|1223|getAttributeNode|300|method|protocol|location|action|send|abort|cssText|th|td|cap|specified|Accept|With|colg|Requested|fast|tfoot|GMT|thead|1970|Jan|attributes|01|Thu|leg|Since|If|opt|Type|Content|embed|open|area|XMLHTTP|hr|Microsoft|onreadystatechange|onload|meta|adobeair|charset|http|1_|img|br|plain|borderLeftWidth|borderTopWidth|abbr'.split('|'),0,{}))

/* - cssQuery.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/cssQuery.js?original=1
eval(__dEcOdE('9 o=5(){9 1o="2.0.2";9 C=/\\s*,\\s*/;9 o=5(s,1b){try{9 m=[];9 u=1c.callee.1L&&!1b;9 b=(1b)?(1b.constructor==1W)?1b:[1b]:[Z];9 25=Q(s).1E(C),i;M(i=0;i<25.q;i++){s=29(25[i]);B(13&&s.1e(0,3).22("")==" *#"){s=s.1e(2);1b=2d([],b,s[1])}1D 1b=b;9 j=0,t,f,a,c="";T(j<s.q){t=s[j++];f=s[j++];c+=t+f;a="";B(s[j]=="("){T(s[j++]!=")"&&j<s.q){a+=s[j]}a=a.1e(0,-1);c+="("+a+")"}B(t==" "&&f=="*"&&s[j]=="#")1l;1b=(u&&19[c])?19[c]:1M(1b,t,f,a);B(u)19[c]=1b}m=m.concat(1b)}1Q o.1U;6 m}catch(e){o.1U=e;6 []}};o.1A=5(){6 "5 o() {\\n  [1o "+1o+"]\\n}"};9 19={};o.1L=Y;o.clearCache=5(s){B(s){s=29(s).22("");1Q 19[s]}1D 19={}};9 1J={};9 1u=Y;o.14=5(n,s){B(1u)1P("$script="+1S(s));1J[n]=1F s()};o.valueOf=5(c){6 c?1P(c):F};9 y={};9 8={};9 7={X:/\\[([\\w-]+(\\|[\\w-]+)?)\\s*(\\W?=)?\\s*([^\\]]*)\\]/};9 l=[];y[" "]=5(r,f,t,n){9 e,i,j;M(i=0;i<f.q;i++){9 s=x(f[i],t,n);M(j=0;(e=s[j]);j++){B(z(e)&&H(e,n))r.K(e)}}};y["#"]=5(r,f,i){9 e,j;B(f.q==1&&f[0]==Z){9 n=Z.getElementById(i);B(n)r.K(n)}1D{M(j=0;(e=f[j]);j++)B(e.1j==i){r.K(e);1s}}};y["."]=5(r,f,c){c=1F 1y("(^|\\\\s)"+c+"(\\\\s|$)");9 e,i;M(i=0;(e=f[i]);i++)B(c.G(e.1x))r.K(e)};y[":"]=5(r,f,p,a){9 t=8[p],e,i;B(t)M(i=0;(e=f[i]);i++)B(t(e,a))r.K(e)};8["link"]=5(e){9 d=D(e);B(d.1G)M(9 i=0;i<d.1G.q;i++){B(d.1G[i]==e)6 15}};8["visited"]=5(e){};9 z=5(e){6(e&&e.1i==1&&e.1a!="!")?e:20};9 A=5(e){T(e&&(e=e.previousSibling)&&!z(e))1l;6 e};9 h=5(e){T(e&&(e=e.nextSibling)&&!z(e))1l;6 e};9 R=5(e){6 z(e.1q)||h(e.1q)};9 16=5(e){6 z(e.1v)||A(e.1v)};9 12=5(e){9 c=[];e=R(e);T(e){c.K(e);e=h(e)}6 c};9 13=15;9 1H=5(e){9 d=D(e);6(typeof d.1C=="unknown")?/\\.24$/i.G(d.URL):Boolean(d.1C=="XML Document")};9 D=5(e){6 e.ownerDocument||e.Z};9 x=5(e,t){6(t=="*"&&e.1Z)?e.1Z:e.x(t)};9 P=5(e,t,n){B(t=="*")6 z(e);B(!H(e,n))6 Y;B(!1H(e))6 e.1a.1m()==t.1m();6 e.1a==t};9 H=5(e,n){6!n||(n=="*")||(e.scopeName==n)};9 V=5(e){6 e.1w};5 2d(r,f,1j){9 m,i,j;M(i=0;i<f.q;i++){B(m=f[i].1Z.item(1j)){B(m.1j==1j)r.K(m);1D B(m.q!=20){M(j=0;j<m.q;j++){B(m[j].1j==1j)r.K(m[j])}}}}6 r};B(![].K)1W.prototype.K=5(){M(9 i=0;i<1c.q;i++){F[F.q]=1c[i]}6 F.q};9 N=/\\|/;5 1M(1b,t,f,a){B(N.G(f)){f=f.1E(N);a=f[0];f=f[1]}9 r=[];B(y[t]){y[t](r,1b,f,a)}6 r};9 S=/^[^\\s>+~]/;9 2e=/[\\s#.:>+~()@]|[^\\s#.:>+~()@]+/g;5 29(s){B(S.G(s))s=" "+s;6 s.X(2e)||[]};9 W=/\\s*([\\s>+~(),]|^|$)\\s*/g;9 I=/([\\s>+~,]|[^(]\\+|^)([#.:@])/g;9 Q=5(s){6 s.O(W,"$1").O(I,"$1*$2")};9 1I={1A:5(){6 "\'"},X:/^(\'[^\']*\')|("[^"]*")$/,G:5(s){6 F.X.G(s)},28:5(s){6 F.G(s)?s:F+s+F},1N:5(s){6 F.G(s)?s.1e(1,-1):s}};9 1p=5(t){6 1I.1N(t)};9 E=/([\\/()[\\]?{}|*+-])/g;5 J(s){6 s.O(E,"\\\\$1")};o.14("1Y-standard",5(){13=1P("Y;/*@cc_on@B(@\\x5fwin32)13=15@end@*/");B(!13){x=5(e,t,n){6 n?e.getElementsByTagNameNS("*",t):e.x(t)};H=5(e,n){6!n||(n=="*")||(e.prefix==n)};1H=Z.1n? 5(e){6/24/i.G(D(e).1n)}:5(e){6 D(e).18.1a!="HTML"};V=5(e){6 e.textContent||e.1w||2b(e)};5 2b(e){9 t="",n,i;M(i=0;(n=e.1r[i]);i++){1t(n.1i){10 11:10 1:t+=2b(n);1s;10 3:t+=n.nodeValue;1s}}6 t}}});o.14("1Y-level2",5(){y[">"]=5(r,f,t,n){9 e,i,j;M(i=0;i<f.q;i++){9 s=12(f[i]);M(j=0;(e=s[j]);j++)B(P(e,t,n))r.K(e)}};y["+"]=5(r,f,t,n){M(9 i=0;i<f.q;i++){9 e=h(f[i]);B(e&&P(e,t,n))r.K(e)}};y["@"]=5(r,f,a){9 t=l[a].G;9 e,i;M(i=0;(e=f[i]);i++)B(t(e))r.K(e)};8["first-1g"]=5(e){6!A(e)};8["1O"]=5(e,c){c=1F 1y("^"+c,"i");T(e&&!e.L("1O"))e=e.17;6 e&&c.G(e.L("1O"))};7.1V=/\\\\:/g;7.1z="@";7.U={};7.O=5(m,a,n,c,v){9 k=F.1z+m;B(!l[k]){a=F.1R(a,c||"",v||"");l[k]=a;l.K(a)}6 l[k].1j};7.1T=5(s){s=s.O(F.1V,"|");9 m;T(m=s.X(F.X)){9 r=F.O(m[0],m[1],m[2],m[3],m[4]);s=s.O(F.X,r)}6 s};7.1R=5(p,t,v){9 a={};a.1j=F.1z+l.q;a.name=p;t=F.U[t];t=t?t(F.L(p),1p(v)):Y;a.G=1F Function("e","6 "+t);6 a};7.L=5(n){1t(n.toLowerCase()){10 "1j":6 "e.1j";10 "class":6 "e.1x";10 "M":6 "e.htmlFor";10 "23":B(13){6 "1S((e.outerHTML.X(/23=\\\\1X?([^\\\\s\\\\1X]*)\\\\1X?/)||[])[1]||\'\')"}}6 "e.L(\'"+n.O(N,":")+"\')"};7.U[""]=5(a){6 a};7.U["="]=5(a,v){6 a+"=="+1I.28(v)};7.U["~="]=5(a,v){6 "/(^| )"+J(v)+"( |$)/.G("+a+")"};7.U["|="]=5(a,v){6 "/^"+J(v)+"(-|$)/.G("+a+")"};9 2c=Q;Q=5(s){6 2c(7.1T(s))}});o.14("1Y-level3",5(){y["~"]=5(r,f,t,n){9 e,i;M(i=0;(e=f[i]);i++){T(e=h(e)){B(P(e,t,n))r.K(e)}}};8["contains"]=5(e,t){t=1F 1y(J(1p(t)));6 t.G(V(e))};8["root"]=5(e){6 e==D(e).18};8["empty"]=5(e){9 n,i;M(i=0;(n=e.1r[i]);i++){B(z(n)||n.1i==3)6 Y}6 15};8["21-1g"]=5(e){6!h(e)};8["only-1g"]=5(e){e=e.17;6 R(e)==16(e)};8["not"]=5(e,s){9 n=o(s,D(e));M(9 i=0;i<n.q;i++){B(n[i]==e)6 Y}6 15};8["26-1g"]=5(e,a){6 1h(e,a,A)};8["26-21-1g"]=5(e,a){6 1h(e,a,h)};8["target"]=5(e){6 e.1j==location.hash.1e(1)};8["1K"]=5(e){6 e.1K};8["enabled"]=5(e){6 e.1k===Y};8["1k"]=5(e){6 e.1k};8["1d"]=5(e){6 e.1d};7.U["^="]=5(a,v){6 "/^"+J(v)+"/.G("+a+")"};7.U["$="]=5(a,v){6 "/"+J(v)+"$/.G("+a+")"};7.U["*="]=5(a,v){6 "/"+J(v)+"/.G("+a+")"};5 1h(e,a,t){1t(a){10 "n":6 15;10 "even":a="2n";1s;10 "odd":a="2n+1"}9 27=12(e.17);5 2a(i){9 i=(t==h)?27.q-i:i-1;6 27[i]==e};B(!1f(a))6 2a(a);a=a.1E("n");9 m=1B(a[0]);9 s=1B(a[1]);B((1f(m)||m==1)&&s==0)6 15;B(m==0&&!1f(s))6 2a(s);B(1f(s))s=0;9 c=1;T(e=t(e))c++;B(1f(m)||m==1)6(t==h)?(c<=s):(s>=c);6(c%m)==s}});1u=15;6 o}();',62,139,'',0,{}))

/* - jquery-integration.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/jquery-integration.js?original=1
var jq=jQuery.noConflict();if(typeof cssQuery=='undefined'){
function cssQuery(s,f){return jq.makeArray(jq(s,f))}};

/* - event-registration.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/event-registration.js?original=1
window.onDOMLoadEvents=new Array();window.DOMContentLoadedInitDone=false;
function addDOMLoadEvent(listener){window.onDOMLoadEvents[window.onDOMLoadEvents.length]=listener}
function DOMContentLoadedInit(){if(window.DOMContentLoadedInitDone) return;window.DOMContentLoadedInitDone=true;var exceptions=new Array();for(var i=0;i<window.onDOMLoadEvents.length;i++){var func=window.onDOMLoadEvents[i];try{func()} catch(e){exceptions[exceptions.length]=e}}
for(var i=0;i<exceptions.length;i++){throw exceptions[i]}}
function DOMContentLoadedScheduler(){if(window.DOMContentLoadedInitDone) return true;if(/KHTML|WebKit/i.test(navigator.userAgent)){if(/loaded|complete/.test(document.readyState)){DOMContentLoadedInit()} else{setTimeout("DOMContentLoadedScheduler()",250)}} else{setTimeout("DOMContentLoadedScheduler()",250)}
return true}
setTimeout("DOMContentLoadedScheduler()",250);if(window.addEventListener){window.addEventListener("load",DOMContentLoadedInit,false);document.addEventListener("DOMContentLoaded",DOMContentLoadedInit,false)} else if(window.attachEvent){window.attachEvent("onload",DOMContentLoadedInit)} else{var _dummy=function(){var $old_onload=window.onload;window.onload=function(e){DOMContentLoadedInit();$old_onload()}}}
/*@cc_on @*/
/*@if (@_win32)
{var proto="src='javascript:void(0)'";if(location.protocol=="https:") proto="src=//0";document.write("<scr"+"ipt id=__ie_onload defer "+proto+"><\/scr"+"ipt>");var script=document.getElementById("__ie_onload");script.onreadystatechange=function(){if(this.readyState=="complete"){DOMContentLoadedInit()}}};/*@end @*/


/* - register_function.js - */
/* Essential javascripts, used a lot. 
 * These should be placed inline
 * We have to be certain they are loaded before anything that uses them 
 */
// Deprecated, use jquery methods directly instead

// check for ie5 mac
var bugRiddenCrashPronePieceOfJunk = (
    navigator.userAgent.indexOf('MSIE 5') != -1
    &&
    navigator.userAgent.indexOf('Mac') != -1
)

// check for W3CDOM compatibility
var W3CDOM = (!bugRiddenCrashPronePieceOfJunk &&
               typeof document.getElementsByTagName != 'undefined' &&
               typeof document.createElement != 'undefined' );

// cross browser function for registering event handlers
var registerEventListener = function(elem, event, func) {
    jq(elem).bind(event, func);
}

// cross browser function for unregistering event handlers
var unRegisterEventListener = function(elem, event, func) {
    jq(elem).unbind(event, func);
}

var registerPloneFunction = jq;

function getContentArea() {
    // returns our content area element
    var node = jq('#region-content,#content');
    return node.length ? node[0] : null;
} 


/* - plone_javascript_variables.js - */


// Global Plone variables that need to be accessible to the Javascripts
var portal_url = 'http://se.math.spbu.ru/SE';
var form_modified_message = 'Ваша форма не была записана. Все внесенные вами изменения будут потеряны';
var form_resubmit_message = 'You already clicked the submit button. Do you really want to submit this form again?';

// the following are flags for mark_special_links.js
// links get the target="_blank" attribute
var external_links_open_new_window = 'false';



/* - nodeutilities.js - */
// These methods have all been deprecated in favor of using jquery.

function wrapNode(node, wrappertype, wrapperclass){
    /* utility function to wrap a node in an arbitrary element of type "wrappertype"
     * with a class of "wrapperclass" */
    jq(node).wrap('<' + wrappertype + '>').parent().addClass(wrapperclass);
};

function nodeContained(innernode, outernode){
    // check if innernode is contained in outernode
    return jq(innernode).parents()
        .filter(function() { return this == outernode }).length > 0;
};

function findContainer(node, func) {
    // Starting with the given node, find the nearest containing element
    // for which the given function returns true.
    p = jq(node).parents().filter(func);
    return p.length ? p.get(0) : false;
};

function hasClassName(node, class_name) {
    return jq(node).hasClass(class_name);
};

function addClassName(node, class_name) {
    jq(node).addClass(class_name);
};

function removeClassName(node, class_name) {
    jq(node).removeClass(class_name);
};

function replaceClassName(node, old_class, new_class, ignore_missing) {
    if (ignore_missing || jq(node).hasClass(old_class))
        jq(node).removeClass(old_class).addClass(new_class);
};

function walkTextNodes(node, func, data) {
    // find all nodes, and call a function for all it's textnodes
    jq(node).find('*').andSelf().contents().each(function() {
        if (this.nodeType == 3) func(this, data);
    });
};

function getInnerTextCompatible(node) {
    return jq(node).text();
};

function getInnerTextFast(node) {
    return jq(node).text();
};

/* This function reorder nodes in the DOM.
 * fetch_func - the function which returns the value for comparison
 * cmp_func - the compare function, if not provided then the string of the
 * value returned by fetch_func is used.
 */
function sortNodes(nodes, fetch_func, cmp_func) {
    // wrapper for sorting
    var SortNodeWrapper = function(node) {
        this.value = fetch_func(node);
        this.cloned_node = node.cloneNode(true);
    }
    SortNodeWrapper.prototype.toString = function() {
        return this.value.toString ? this.value.toString() : this.value;
    }

    // wrap nodes
    var items = jq(nodes).map(function() { return new SortNodeWrapper(this); });

    //sort
    if (cmp_func) items.sort(cmp_func);
    else          items.sort();

    // reorder nodes
    jq.each(items, function(i) { jq(nodes[i]).replace(this.cloned_node); });
};

function copyChildNodes(srcNode, dstNode) {
    jq(srcNode).children().clone().appendTo(jq(dstNode));
}


/* - cookie_functions.js - */
function createCookie(name,value,days) {
    if (days) {
        var date = new Date();
        date.setTime(date.getTime()+(days*24*60*60*1000));
        var expires = "; expires="+date.toGMTString();
    } else {
        expires = "";
    }
    document.cookie = name+"="+escape(value)+expires+"; path=/;";
};

function readCookie(name) {
    var nameEQ = name + "=";
    var ca = document.cookie.split(';');
    for(var i=0;i < ca.length;i++) {
        var c = ca[i];
        while (c.charAt(0)==' ') {
            c = c.substring(1,c.length);
        }
        if (c.indexOf(nameEQ) == 0) {
            return unescape(c.substring(nameEQ.length,c.length));
        }
    }
    return null;
};


/* - livesearch.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/livesearch.js?original=1
var livesearch=function(){var _2=400;var _7=400;var _0={};var _1="LSHighlight";function _5(f,i){var l=null;var r=null;var c={};var q="livesearch_reply";if(typeof portal_url!="undefined")q=portal_url+"/"+q;var re=f.find('div.LSResult');var s=f.find('div.LSShadow');var p=f.find('input[name=path]');function _12(){re.hide();l=null};function _6(){window.setTimeout('livesearch.hide("'+f.attr('id')+'")',_7)};function _11(d){re.show();s.html(d)};function _14(){if(l==i.value){return}l=i.value;if(r&&r.readyState<4)r.abort();if(i.value.length<2){_12();return}var qu={q:i.value};if(p.length&&p[0].checked)qu['path']=p.val();qu=jq.param(qu);if(c[qu]){_11(c[qu]);return}r=jq.get(q,qu,function(d){_11(d);c[qu]=d},'text')};function _4(){window.setTimeout('livesearch.search("'+f.attr('id')+'")',_2)};return{hide:_12,hide_delayed:_6,search:_14,search_delayed:_4}};function _3(f){var t=null;var re=f.find('div.LSResult');var s=f.find('div.LSShadow');function _16(){c=s.find('li.LSHighlight').removeClass(_1);p=c.prev('li');if(!p.length)p=s.find('li:last');p.addClass(_1);return false};function _9(){c=s.find('li.LSHighlight').removeClass(_1);n=c.next('li');if(!n.length)n=s.find('li:first');n.addClass(_1);return false};function _8(){s.find('li.LSHighlight').removeClass(_1);re.hide()};function _10(e){window.clearTimeout(t);switch(e.keyCode){case 38:return _16();case 40:return _9();case 27:return _8();case 37:break;case 39:break;default:{t=window.setTimeout('livesearch.search("'+f.attr('id')+'")',_2)}}};function _13(){var t=s.find('li.LSHighlight a').attr('href');if(!t)return;window.location=t;return false};return{handler:_10,submit:_13}};function _15(i){var i='livesearch'+i;var f=jq(this).parents('form:first');var k=_3(f);_0[i]=_5(f,this);f.attr('id',i).css('white-space','nowrap').submit(k.submit);jq(this).attr('autocomplete','off').keydown(k.handler).focus(_0[i].search_delayed).blur(_0[i].hide_delayed)};jq(function(){jq("#searchGadget,input.portlet-search-gadget").each(_15)});return{search:function(id){_0[id].search()},hide:function(id){_0[id].hide()}}}();

/* - select_all.js - */
// Functions for selecting all checkboxes in folder_contents/search_form view
function toggleSelect(selectbutton, id, initialState, formName) {
    /* required selectbutton: you can pass any object that will function as a toggle
     * optional id: id of the the group of checkboxes that needs to be toggled (default=ids:list
     * optional initialState: initial state of the group. (default=false)
     * e.g. folder_contents is false, search_form=true because the item boxes
     * are checked initially.
     * optional formName: name of the form in which the boxes reside, use this if there are more
     * forms on the page with boxes with the same name
     */
    id=id || 'ids:list'  // defaults to ids:list, this is the most common usage
    var state = selectbutton.isSelected;
    state = state == null ? Boolean(initialState) : state;

    // create and use a property on the button itself so you don't have to 
    // use a global variable and we can have as much groups on a page as we like.
    selectbutton.isSelected = !state;
    jq(selectbutton).attr('src', portal_url+'/select_'+(state?'all':'none')+'_icon.gif');
    var base = formName ? jq(document.forms[formName]) : jq(document);
    base.find(':checkbox[name=' + id + ']').attr('checked', !state);
}


/* - dragdropreorder.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/dragdropreorder.js?original=1
var ploneDnDReorder={};ploneDnDReorder.dragging=null;ploneDnDReorder.table=null;ploneDnDReorder.rows=null;ploneDnDReorder.doDown=function(e){var dragging=jq(this).parents('.draggable:first');if(!dragging.length) return;ploneDnDReorder.rows.mousemove(ploneDnDReorder.doDrag);ploneDnDReorder.dragging=dragging;dragging._position=ploneDnDReorder.getPos(dragging);dragging.addClass("dragging");return false};ploneDnDReorder.getPos=function(node){var pos=node.parent().children('.draggable').index(node[0]);return pos==-1?null:pos};ploneDnDReorder.doDrag=function(e){var dragging=ploneDnDReorder.dragging;if(!dragging) return;var target=this;if(!target) return;if(jq(target).attr('id')!=dragging.attr('id')){ploneDnDReorder.swapElements(jq(target),dragging)};return false};ploneDnDReorder.swapElements=function(child1,child2){var parent=child1.parent();var items=parent.children('[id]');items.removeClass('even').removeClass('odd');if(child1[0].swapNode){child1[0].swapNode(child2[0])} else{var t=parent[0].insertBefore(document.createTextNode(''),child1[0]);child1.insertBefore(child2);child2.insertBefore(t);jq(t).remove()};parent.children('[id]:odd').addClass('even');parent.children('[id]:even').addClass('odd')};ploneDnDReorder.doUp=function(e){var dragging=ploneDnDReorder.dragging;if(!dragging) return;dragging.removeClass("dragging");ploneDnDReorder.updatePositionOnServer();dragging._position=null;try{delete dragging._position} catch(e){};dragging=null;ploneDnDReorder.rows.unbind('mousemove',ploneDnDReorder.doDrag);return false};ploneDnDReorder.updatePositionOnServer=function(){var dragging=ploneDnDReorder.dragging;if(!dragging) return;var delta=ploneDnDReorder.getPos(dragging)-dragging._position;if(delta==0){return};var args={item_id:dragging.attr('id').substr('folder-contents-item-'.length)};args['delta:int']=delta;jQuery.post('folder_moveitem',args)};

/* - mark_special_links.js - */
/* Scan all links in the document and set classes on them if
 * they point outside the site, or are special protocols
 * To disable this effect for links on a one-by-one-basis,
 * give them a class of 'link-plain'
 *
 * NOTE: This script is no longer hooked up, since we use CSS to do this now.
 *       (see public.css for the implementation)
 *       It's not removed from existing sites that use it, but new sites will
 *       not have it enabled. The CSS approach works in all modern browsers,
 *       but not Internet Explorer 6. It works fine in IE7, however.
 */

function scanforlinks() {
    // first make external links open in a new window, afterwards do the
    // normal plone link wrapping in only the content area

    if (typeof external_links_open_new_window == 'string')
        var elonw = external_links_open_new_window.toLowerCase() == 'true';
    else elonw = false;

    var url = window.location.protocol + '//' + window.location.host;

    if (elonw)
        // all http links (without the link-plain class), not within this site
        jq('a[href^=http]:not(.link-plain):not([href^=' + url + '])')
            .attr('target', '_blank');

    var protocols = /^(mailto|ftp|news|irc|h323|sip|callto|https|feed|webcal)/;
    var contentarea = jq(getContentArea());

    // All links with an http href (without the link-plain class), not within this site,
    // and no img children should be wrapped in a link-external span
    contentarea.find(
        'a[href^=http]:not(.link-plain):not([href^=' + url + ']):not(:has(img))')
        .wrap('<span>').parent().addClass('link-external')
    // All links without an http href (without the link-plain class), not within this site,
    // and no img children should be wrapped in a link-[protocol] span
    contentarea.find(
        'a[href]:not([href^=http]):not(.link-plain):not([href^=' + url + ']):not(:has(img))')
        .each(function() {
            // those without a http link may have another interesting protocol
            // wrap these in a link-[protocol] span
            if (res = protocols.exec(this.href))
                jq(this).wrap('<span>').parent().addClass('link-', res[0]);
        });
};
jq(scanforlinks);


/* - collapsiblesections.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/collapsiblesections.js?original=1
function activateCollapsibles(){jq('dl.collapsible').find('dt.collapsibleHeader:first').click(function(){var c=jq(this).parents('dl.collapsible:first');if(!c)return true;var t=c.hasClass('inline')?'Inline':'Block';c.toggleClass('collapsed'+t+'Collapsible').toggleClass('expanded'+t+'Collapsible')}).end().each(function(){var s=jq(this).hasClass('collapsedOnLoad')?'collapsed':'expanded';var t=jq(this).hasClass('inline')?'Inline':'Block';jq(this).removeClass('collapsedOnLoad').addClass(s+t+'Collapsible')})};jq(activateCollapsibles);

/* - form_tabbing.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/form_tabbing.js?original=1
var ploneFormTabbing={};ploneFormTabbing._toggleFactory=function(container,tab_ids,panel_ids){return function(e){jq(tab_ids).removeClass('selected');jq(panel_ids).addClass('hidden');var orig_id=this.tagName.toLowerCase()=='a'?'#'+this.id:jq(this).val();var id=orig_id.replace(/^#fieldsetlegend-/,"#fieldset-");jq(orig_id).addClass('selected');jq(id).removeClass('hidden');jq(container).find("input[name=fieldset.current]").val(orig_id);return false}};ploneFormTabbing._buildTabs=function(container,legends){var threshold=6;var tab_ids=[];var panel_ids=[];legends.each(function(i){tab_ids[i]='#'+this.id;panel_ids[i]=tab_ids[i].replace(/^#fieldsetlegend-/,"#fieldset-")});var handler=ploneFormTabbing._toggleFactory(container,tab_ids.join(','),panel_ids.join(','));if(legends.length>threshold){var tabs=document.createElement("select");var tabtype='option';jq(tabs).change(handler).addClass('noUnloadProtection')} else{var tabs=document.createElement("ul");var tabtype='li'}
jq(tabs).addClass('formTabs');legends.each(function(){var tab=document.createElement(tabtype);jq(tab).addClass('formTab');if(legends.length>threshold){jq(tab).text(jq(this).text());tab.id=this.id;tab.value='#'+this.id} else{var a=document.createElement("a");a.id=this.id;a.href="#"+this.id;jq(a).click(handler);var span=document.createElement("span");jq(span).text(jq(this).text());a.appendChild(span);tab.appendChild(a)}
tabs.appendChild(tab);jq(this).remove()});jq(tabs).children(':first').addClass('firstFormTab');jq(tabs).children(':last').addClass('lastFormTab');return tabs};ploneFormTabbing.select=function($which){if(typeof $which=="string")
$which=jq($which.replace(/^#fieldset-/,"#fieldsetlegend-"));if($which[0].tagName.toLowerCase()=='a'){$which.click();return true} else if($which[0].tagName.toLowerCase()=='option'){$which.attr('selected',true);$which.parent().change();return true} else{$which.change();return true}
return false};ploneFormTabbing.initializeDL=function(){var tabs=jq(ploneFormTabbing._buildTabs(this,jq(this).children('dt')));jq(this).before(tabs);jq(this).children('dd').addClass('formPanel');tabs=tabs.find('li.formTab a,option.formTab');if(tabs.length)
ploneFormTabbing.select(tabs.filter(':first'))};ploneFormTabbing.initializeForm=function(){var fieldsets=jq(this).children('fieldset');if(!fieldsets.length) return;var tabs=ploneFormTabbing._buildTabs(this,fieldsets.children('legend'));jq(this).prepend(tabs);fieldsets.addClass("formPanel");jq(this).find('input[name=fieldset.current]').addClass('noUnloadProtection');var tab_inited=false;jq(this).find('.formPanel:has(div.field.error)').each(function(){var id=this.id.replace(/^fieldset-/,"#fieldsetlegend-");var tab=jq(id);tab.addClass("notify");if(tab.length&&!tab_inited)
tab_inited=ploneFormTabbing.select(tab)});jq(this).find('.formPanel:has(div.field span.fieldRequired)').each(function(){var id=this.id.replace(/^fieldset-/,"#fieldsetlegend-");jq(id).addClass('required')});if(!tab_inited){jq('input[name=fieldset.current][value^=#]').each(function(){tab_inited=ploneFormTabbing.select(jq(this).val())})}
if(!tab_inited){var tabs=jq("form.enableFormTabbing li.formTab a,"+"form.enableFormTabbing option.formTab,"+"div.enableFormTabbing li.formTab a,"+"div.enableFormTabbing option.formTab");if(tabs.length)
ploneFormTabbing.select(tabs.filter(':first'))}
jq("#archetypes-schemata-links").addClass('hiddenStructure');jq("div.formControls input[name=form_previous],"+"div.formControls input[name=form_next]").remove()};jq(function(){jq("form.enableFormTabbing,div.enableFormTabbing").each(ploneFormTabbing.initializeForm);jq("dl.enableFormTabbing").each(ploneFormTabbing.initializeDL)});

/* - highlightsearchterms.js - */
function highlightTermInNode(node, word) {
    var contents = node.nodeValue;
    if (jq(node).parent().hasClass("highlightedSearchTerm")) return;
    
    // Internet Explorer cannot create simple <span> tags without content
    // otherwise it'd be jq('<span>').addClass(...).text(content)
    var highlight = function(content) {
        return jq('<span class="highlightedSearchTerm">' + 
                  content + '</span>');
    }
    
    while (contents && (index = contents.toLowerCase().indexOf(word)) > -1) {
        // replace the node with [before]<span>word</span>[after]
        jq(node)
            .before(document.createTextNode(contents.substr(0, index)))
            .before(highlight(contents.substr(index, word.length)))
            .before(document.createTextNode(contents.substr(index+word.length)));
        var next = node.previousSibling; // text after the span
        jq(node).remove(); 
        // wash, rinse and repeat
        node = next; contents = node.nodeValue;
    }
}

function highlightSearchTerms(terms, startnode) {
    if (!terms || !startnode) return;

    jq.each(terms, function(i, term) {
        term = term.toLowerCase();
        // don't highlight reserved catalog search terms
        if (!term || /(not|and|or)/.test(term)) return;
        jq(startnode).find('*').andSelf().contents().each(function() {
            if (this.nodeType == 3) highlightTermInNode(this, term);
        });
    });
}

function getSearchTermsFromURI(uri) {
    var query;
    if (typeof decodeURI != 'undefined') {
        query = decodeURI(uri);
    } else if (typeof unescape != 'undefined') {
        // _robert_ ie 5 does not have decodeURI 
        query = unescape(uri);
    } else {
        // we just try to be lucky, for single words this will still work
    }
    var result = new Array();
    if (window.decodeReferrer) {
        var referrerSearch = decodeReferrer();
        if (null != referrerSearch && referrerSearch.length > 0) {
            result = referrerSearch;
        }
    }
    var qfinder = new RegExp("(searchterm|SearchableText)=([^&]*)", "gi");
    var qq = qfinder.exec(query);
    if (qq && qq[2]) {
        var terms = qq[2].replace(/\+/g,' ').split(' ');
        result.push.apply(result, jq.grep(terms, function(a) { return a != ""}));
        return result;
    }
    return result.length == 0 ? false : result;
}

jq(function() {
    // search-term-highlighter function --  Geir Baekholt
    var terms = getSearchTermsFromURI(window.location.search);
    // make sure we start the right place so we don't higlight menuitems or breadcrumb
    highlightSearchTerms(terms, getContentArea());
});



/* - se-highlight.js - */
/* List of search engine matchers and the referrer search
 * code where carefully borrowed from the
 * "Search Engine Keyword Highlight" by Scott Yang,
 * see http://fucoder.com/code/se-hilite/ for further
 * details.
 */
var searchEngines = [
    ['^http://([^.]+\\.)?google.*', 'q='],              // Google
    ['^http://search\\.yahoo.*', 'p='],                // Yahoo
    ['^http://search\\.msn.*', 'q='],                  // MSN
    ['^http://search\\.aol.*', 'userQuery='],          // AOL
    ['^http://(www\\.)?altavista.*', 'q='],            // AltaVista
    ['^http://(www\\.)?feedster.*', 'q='],             // Feedster
    ['^http://search\\.lycos.*', 'query='],            // Lycos
    ['^http://(www\\.)?alltheweb.*', 'q='],             // AllTheWeb
    ['^http://(www\\.)?ask\\.com.*', 'q=']                   // Ask.com
]

function decodeReferrer(ref) {
    // checks if we are beeing searched by a search engine
    if (null == ref && document.referrer) {
        ref = document.referrer;
    }
    if (!ref) return null;

    var match = new RegExp('');
    var seQuery = '';
    for (var i = 0; i < searchEngines.length; i ++) {
        if (!match.compile) {
            // Safari doesn't support the non-standard compile method
            match = new RegExp(searchEngines[i][0], 'i');
        } else {
            match.compile(searchEngines[i][0], 'i');
        }
        if (ref.match(match)) {
            
            if (!match.compile) {
                match = new RegExp('^.*[?&]'+searchEngines[i][1]+'([^&]+)&?.*$', 'i');
            } else {
                match.compile('^.*[?&]'+searchEngines[i][1]+'([^&]+)&?.*$');
            }
            seQuery = ref.replace(match, '$1');
            if (seQuery) {
                seQuery = decodeURIComponent(seQuery);
                seQuery = seQuery.replace(/\'|"/, '');
                return seQuery.split(/[\s,\+\.]+/);
            }

        }
    }
    return null;
}


/* - first_input_focus.js - */
// Focus on error or first element in a form with class="enableAutoFocus"
jq(function() {
    if (jq("form div.error :input:first").focus().length) return;
    jq("form.enableAutoFocus :input:not(.formTabs):visible:first").focus();
});


/* - accessibility.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/accessibility.js?original=1
function setBaseFontSize(f,r){var b=jq('body');if(r){b.removeClass('smallText').removeClass('largeText');createCookie("fontsize",f,365)}b.addClass(f)};jq(function(){var f=readCookie("fontsize");if(f)setBaseFontSize(f,0)});

/* - styleswitcher.js - */
// StyleSwitcher functions written by Paul Sowden
function setActiveStyleSheet(title, reset) {
    jq('link[rel*=style][title]').attr('disabled', true)
        .find('[title=' + title + ']').attr('disabled', false);
    if (reset) createCookie("wstyle", title, 365);
};

jq(function() {
    var style = readCookie("wstyle");
    if (style != null) setActiveStyleSheet(style, 0);
});


/* - toc.js - */
// http://se.math.spbu.ru/SE/portal_javascripts/toc.js?original=1
jq(function(){var dest=jq('dl.toc dd.portletItem');var content=getContentArea();if(!content||!dest.length) return;dest.empty();var location=window.location.href;if(window.location.hash)
location=location.substring(0,location.lastIndexOf(window.location.hash));var stack=[];jq(content).find('*').filter(function(){return/^h[1234]$/.test(this.tagName.toLowerCase())}).not('.documentFirstHeading').each(function(i){var level=this.nodeName.charAt(1)-1;while(stack.length<level){var ol=jq('<ol>');if(stack.length){var li=jq(stack[stack.length-1]).children('li:last')
if(!li.length)
li=jq('<li>').appendTo(jq(stack[stack.length-1]))
li.append(ol)}
stack.push(ol)}
while(stack.length>level) stack.pop();jq(this).before(jq('<a name="section-'+i+'" />'));jq('<li>').append(jq('<a />').text(jq(this).text()).attr('href',location+'#section-'+i)).appendTo(jq(stack[stack.length-1]))});if(stack.length){jq('dl.toc').show();dest.append(stack[0])}});

