document.addEventListener("DOMContentLoaded", function () {
  const logo = document.querySelector(".md-header__button.md-logo");
  if (logo) {
    logo.setAttribute("title", "Visit UniTrento homepage");
    logo.style.cursor = "pointer";

    logo.addEventListener("click", function (event) {
      event.preventDefault();
      window.open("https://webapps.unitn.it/gestionecorsi", "_blank");
    });
  }
});

document$.subscribe(function() {
  var tables = document.querySelectorAll("article table")
  tables.forEach(function(table) {
    new Tablesort(table)
  })
})

document$.subscribe(() => {
  hljs.highlightAll()
})