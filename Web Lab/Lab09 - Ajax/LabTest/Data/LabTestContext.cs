using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;

namespace LabTest.Models
{
    public class LabTestContext : DbContext
    {
        public LabTestContext (DbContextOptions<LabTestContext> options)
            : base(options)
        {
        }

        public DbSet<LabTest.Models.Student> Student { get; set; }
    }
}
