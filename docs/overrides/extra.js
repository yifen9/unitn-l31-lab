document$.subscribe(function() {
  var tables = document.querySelectorAll("article table")
  tables.forEach(function(table) {
    new Tablesort(table)
  });
});

document$.subscribe(() => {
  const logos = document.querySelectorAll(".md-logo");

  logos.forEach(logo => {
    const img = logo.querySelector("img");
    if (img) {
      img.style.cursor = "pointer";
      img.title = "Visit UniTrento homepage";

      img.onclick = () => {
        window.open("https://webapps.unitn.it/gestionecorsi", "_blank");
      };
    }
  });
});

document$.subscribe(() => {
  document.querySelectorAll('a[href^="http"]').forEach(link => {
    if (!link.href.includes(location.hostname)) {
      link.setAttribute("target", "_blank");
      link.setAttribute("rel", "noopener noreferrer");
    }
  });
});