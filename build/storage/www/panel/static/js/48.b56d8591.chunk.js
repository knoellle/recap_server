(window.webpackJsonp=window.webpackJsonp||[]).push([[48],{1163:function(e,t,a){"use strict";a.r(t);var n=a(228),c=a(229),r=a(231),l=a(230),i=a(233),o=a(232),u=a(3),s=a.n(u),m=a(889),d=a(890),f=a(892),p=a(894),v=a(893),E=a(944),h=a(956),b=function(e){function t(e){var a;Object(n.a)(this,t),a=Object(r.a)(this,Object(l.a)(t).call(this,e));var c=e.match.params.id;a.state={};var o=Object(i.a)(a);return h.a.dlsApiGet({method:"api.game.getUserInfo",mail:c},function(e){o.setState({user:e.data.user})},function(e){}),a}return Object(o.a)(t,e),Object(c.a)(t,[{key:"render",value:function(){var e=this.state.user;return void 0===e?"Loading...":s.a.createElement("div",{className:"animated fadeIn"},s.a.createElement(m.a,null,s.a.createElement(d.a,{lg:6},s.a.createElement(f.a,null,s.a.createElement(p.a,null,s.a.createElement("strong",null,s.a.createElement("i",{className:"icon-info pr-1"}),"User mail: ",e.email)),s.a.createElement(v.a,null,s.a.createElement(E.a,{responsive:!0,striped:!0,hover:!0},s.a.createElement("tbody",null,s.a.createElement("tr",null,s.a.createElement("td",null,"Name:"),s.a.createElement("td",null,s.a.createElement("strong",null,e.name))))))))))}}]),t}(u.Component);t.default=b},956:function(e,t,a){"use strict";var n=a(228),c=a(229),r=a(985),l=a.n(r),i=function(){function e(){Object(n.a)(this,e)}return Object(c.a)(e,null,[{key:"dlsApiGet",value:function(e,t,a){var n="";for(var c in e)""!=n&&(n+="&"),n+=c+"="+encodeURIComponent(e[c]);l.a.get("/dls/api?"+n).then(function(e){t(e)}).catch(function(e){a(e)})}},{key:"gameApiGet",value:function(e,t,a){var n="";for(var c in e)""!=n&&(n+="&"),n+=c+"="+encodeURIComponent(e[c]);l.a.get("/game/api?"+n).then(function(e){t(e)}).catch(function(e){a(e)})}}]),e}();t.a=i}}]);
//# sourceMappingURL=48.b56d8591.chunk.js.map