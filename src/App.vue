
<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <LinkTree links={{ routes }}/>
    <!-- <HelloWorld/> -->
  </div>
</template>

<script>
import LinkTree from './components/LinkTree.vue'
// import HelloWorld from './components/HelloWorld.vue'

export default {
  name: 'app',
  components: {
    LinkTree
  },
  data: () => ({
    routes: [{
      url: 'www.kombucha.com',
      title: 'kombucha'
    }]
  })
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
