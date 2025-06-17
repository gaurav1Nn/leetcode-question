/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
  return this.length ? this.slice(-1)[0] : -1;
};
/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */