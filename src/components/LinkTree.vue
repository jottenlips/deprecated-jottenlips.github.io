<template>
  <div class="hello">
    <h3>Essential Links</h3>
        <h3>Essential Links</h3>

    <h3>Essential Links</h3>

    <h3>Essential Links</h3>

    <ul id="example-1">
        <!-- <li v-for="(route, index)  in links"  :key="index">
            <a href={{ route.url }} target="_blank" rel="noopener">{{ route.title }}</a>
        </li> -->
    </ul>
  </div>
</template>

<script>

export default {
  name: 'LinkTree',
  el: '#example-1',
  props: {
    links: [{
        title: String,
        url: String
    }]
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}
ul {
  list-style-type: none;
  padding: 0;
}
li {
  display: inline-block;
  margin: 0 10px;
}
a {
  color: #42b983;
}
</style>
