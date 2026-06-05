// Header scroll state
const header = document.querySelector("[data-header]");

function updateHeader() {
  if (!header) return;
  header.classList.toggle("is-scrolled", window.scrollY > 12);
}

updateHeader();
window.addEventListener("scroll", updateHeader, { passive: true });

// Hero load animation
window.addEventListener("load", () => {
  document.querySelectorAll(".reveal-hero").forEach((element) => {
    element.classList.add("is-visible");
  });
});

// Project section reveal animation
const revealElements = document.querySelectorAll(".reveal, .reveal-card");
const revealObserver = new IntersectionObserver(
  (entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        entry.target.classList.add("is-visible");
        revealObserver.unobserve(entry.target);
      }
    });
  },
  {
    threshold: 0.16,
    rootMargin: "0px 0px -70px 0px"
  }
);

revealElements.forEach((element) => revealObserver.observe(element));

// Smooth scrolling for the Projects navigation link
document.querySelectorAll('a[href^="#"]').forEach((link) => {
  link.addEventListener("click", (event) => {
    const targetId = link.getAttribute("href");
    if (!targetId) return;

    if (targetId === "#") {
      event.preventDefault();
      return;
    }

    const target = document.querySelector(targetId);
    if (!target) return;

    event.preventDefault();
    target.scrollIntoView({ behavior: "smooth", block: "start" });
  });
});

// Footer year
const yearElement = document.querySelector("[data-year]");
if (yearElement) {
  yearElement.textContent = new Date().getFullYear();
}
