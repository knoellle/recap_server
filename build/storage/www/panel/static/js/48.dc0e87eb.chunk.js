(window.webpackJsonp=window.webpackJsonp||[]).push([[48],{1173:function(e,t,a){"use strict";a.r(t);var r=a(228),n=a(229),i=a(231),s=a(230),d=a(233),l=a(232),o=a(3),u=a.n(o),c=a(177),m=a(901),g=a(889),f=a(890),v=a(892),h=a(894),E=a(893),b=a(928),p=a(1108),A=a.n(p),k=function(){function e(){Object(r.a)(this,e)}return Object(n.a)(e,null,[{key:"dlsApiGet",value:function(e,t,a){var r="";for(var n in e)""!=r&&(r+="&"),r+=n+"="+encodeURIComponent(e[n]);A.a.get("/dls/api?"+r).then(function(e){t(e)}).catch(function(e){a(e)})}}]),e}();a(956);function M(e){var t=e.user;t.id=e.key;var a="/users/".concat(t.id);return u.a.createElement("tr",{key:t.id.toString()},u.a.createElement("th",{scope:"row"},u.a.createElement(c.Link,{to:a},t.id)),u.a.createElement("td",null,u.a.createElement(c.Link,{to:a},t.email)),u.a.createElement("td",null,u.a.createElement(c.Link,{to:a},u.a.createElement(m.a,{color:function(e){return e.logged?"success":"primary"}(t)},function(e){return e.logged?"Logged":""}(t)))))}var S=function(e){function t(e){var a;Object(r.a)(this,t),(a=Object(i.a)(this,Object(s.a)(t).call(this,e))).state={};var n=Object(d.a)(a);return k.dlsApiGet({method:"api.game.listUsers"},function(e){n.setState({usersList:e.data.users})},function(e){}),a}return Object(l.a)(t,e),Object(n.a)(t,[{key:"render",value:function(){return u.a.createElement("div",{className:"animated fadeIn"},u.a.createElement(g.a,null,u.a.createElement(f.a,{xl:6},u.a.createElement(v.a,null,u.a.createElement(h.a,null,u.a.createElement("i",{className:"fa fa-align-justify"})," Users"),u.a.createElement(E.a,null,u.a.createElement(b.a,{responsive:!0,hover:!0},u.a.createElement("thead",null,u.a.createElement("tr",null,u.a.createElement("th",{scope:"col"},"id"),u.a.createElement("th",{scope:"col"},"name"),u.a.createElement("th",{scope:"col"},"status"))),u.a.createElement("tbody",null,void 0===this.state.usersList?"Loading...":this.state.usersList.map(function(e,t){return u.a.createElement(M,{key:t,user:e})}))))))))}}]),t}(o.Component);t.default=S},956:function(e,t,a){"use strict";t.a=[{id:0,name:"John Doe",registered:"2018/01/01",role:"Guest",status:"Pending"},{id:1,name:"Samppa Nori",registered:"2018/01/01",role:"Member",status:"Active"},{id:2,name:"Estavan Lykos",registered:"2018/02/01",role:"Staff",status:"Banned"},{id:3,name:"Chetan Mohamed",registered:"2018/02/01",role:"Admin",status:"Inactive"},{id:4,name:"Derick Maximinus",registered:"2018/03/01",role:"Member",status:"Pending"},{id:5,name:"Friderik D\xe1vid",registered:"2018/01/21",role:"Staff",status:"Active"},{id:6,name:"Yiorgos Avraamu",registered:"2018/01/01",role:"Member",status:"Active"},{id:7,name:"Avram Tarasios",registered:"2018/02/01",role:"Staff",status:"Banned"},{id:8,name:"Quintin Ed",registered:"2018/02/01",role:"Admin",status:"Inactive"},{id:9,name:"En\xe9as Kwadwo",registered:"2018/03/01",role:"Member",status:"Pending"},{id:10,name:"Agapetus Tade\xe1\u0161",registered:"2018/01/21",role:"Staff",status:"Active"},{id:11,name:"Carwyn Fachtna",registered:"2018/01/01",role:"Member",status:"Active"},{id:12,name:"Nehemiah Tatius",registered:"2018/02/01",role:"Staff",status:"Banned"},{id:13,name:"Ebbe Gemariah",registered:"2018/02/01",role:"Admin",status:"Inactive"},{id:14,name:"Eustorgios Amulius",registered:"2018/03/01",role:"Member",status:"Pending"},{id:15,name:"Leopold G\xe1sp\xe1r",registered:"2018/01/21",role:"Staff",status:"Active"},{id:16,name:"Pompeius Ren\xe9",registered:"2018/01/01",role:"Member",status:"Active"},{id:17,name:"Pa\u0109jo Jadon",registered:"2018/02/01",role:"Staff",status:"Banned"},{id:18,name:"Micheal Mercurius",registered:"2018/02/01",role:"Admin",status:"Inactive"},{id:19,name:"Ganesha Dubhghall",registered:"2018/03/01",role:"Member",status:"Pending"},{id:20,name:"Hiroto \u0160imun",registered:"2018/01/21",role:"Staff",status:"Active"},{id:21,name:"Vishnu Serghei",registered:"2018/01/01",role:"Member",status:"Active"},{id:22,name:"Zbyn\u011bk Phoibos",registered:"2018/02/01",role:"Staff",status:"Banned"},{id:23,name:"Einar Randall",registered:"2018/02/01",role:"Admin",status:"Inactive"},{id:24,name:"F\xe9lix Troels",registered:"2018/03/21",role:"Staff",status:"Active"},{id:25,name:"Aulus Agmundr",registered:"2018/01/01",role:"Member",status:"Pending"},{id:42,name:"Ford Prefex",registered:"2001/05/21",role:"Alien",status:"Don't panic!"}]}}]);
//# sourceMappingURL=48.dc0e87eb.chunk.js.map