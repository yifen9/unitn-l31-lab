document$.subscribe(function() {
  var tables = document.querySelectorAll("article table")
  tables.forEach(function(table) {
    new Tablesort(table)
  });
});

document.addEventListener("DOMContentLoaded", () => {
  const logo = document.querySelector(".md-header__button.md-logo");
  if (logo) {
    logo.href = "https://webapps.unitn.it/gestionecorsi";
    logo.setAttribute("target", "_blank");
    logo.setAttribute("title", "Visit UniTrento homepage");
  }
});

document$.subscribe(() => {
  document.querySelectorAll('a[href^="http"]').forEach(link => {
    if (!link.href.includes(location.hostname)) {
      link.setAttribute("target", "_blank");
      link.setAttribute("rel", "noopener noreferrer");
    }
  });
});